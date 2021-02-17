#include "enjinsdk/PusherEventService.hpp"

#include "AppChannel.hpp"
#include "EventTypeDef.hpp"
#include "PlayerChannel.hpp"
#include "TokenChannel.hpp"
#include "WalletChannel.hpp"
#include <algorithm>
#include <utility>

namespace enjin::sdk::events {

PusherEventService::PusherEventService(std::unique_ptr<websockets::IWebsocketClient> ws_client)
        : ws_client(std::move(ws_client)) {
}

PusherEventService::PusherEventService(std::unique_ptr<websockets::IWebsocketClient> ws_client,
                                       models::Platform platform)
        : ws_client(std::move(ws_client)), platform(std::move(platform)) {
}

void PusherEventService::start() {
    shutdown();

    std::optional<models::Notifications> notifications = platform->get_notifications();
    if (!notifications.has_value()) {
        return;
    }

    std::optional<models::Pusher> pusher = notifications->get_pusher();
    if (!pusher.has_value() || !pusher->get_options().has_value()) {
        return;
    }

    std::optional<std::string> key = pusher->get_key();
    std::optional<std::string> cluster = pusher->get_options()->get_cluster();
    std::optional<bool> encrypted = pusher->get_options()->get_encrypted();
    if (!key.has_value() || key->empty() || !cluster.has_value() || cluster->empty()) {
        return;
    }

    pusher::PusherOptions options = pusher::PusherOptions()
            .set_cluster(cluster.value())
            .set_encrypted(encrypted.value());
    pusher_client = std::make_unique<pusher::PusherClient>(ws_client, key.value(), options);

    listener = std::make_shared<PusherEventListener>(*this);

    pusher_client->connect(
            [this](pusher::ConnectionState state) { // On connection state change
                // TODO: Log event service state.

                if (state == pusher::ConnectionState::CONNECTED && connected_handler.has_value()) {
                    connected_handler.value()();
                } else if (state == pusher::ConnectionState::DISCONNECTED && disconnected_handler.has_value()) {
                    disconnected_handler.value()();
                }
            },
            [this](const std::exception& e) { // On error
                if (error_handler.has_value()) {
                    error_handler.value()(e);
                } else {
                    // TODO: Log exception.
                }
            });
}

void PusherEventService::start(models::Platform platform) {
    PusherEventService::platform = std::move(platform);
    start();
}

void PusherEventService::shutdown() {
    if (pusher_client != nullptr) {
        pusher_client->disconnect();
    }
}

bool PusherEventService::is_connected() {
    return pusher_client != nullptr && pusher_client->get_state() == pusher::ConnectionState::CONNECTED;
}

bool PusherEventService::is_registered(IEventListener& listener) {
    auto loc = std::find_if(listeners.begin(),
                            listeners.end(),
                            [&listener](const std::unique_ptr<EventListenerRegistration>& r) {
                                return &r->get_listener() == &listener;
                            });
    return loc != listeners.end();
}

void PusherEventService::set_connected_handler(const std::function<void()>& handler) {
    connected_handler = handler;
}

void PusherEventService::set_disconnected_handler(const std::function<void()>& handler) {
    disconnected_handler = handler;
}

void PusherEventService::set_error_handler(const std::function<void(const std::exception&)>& handler) {
    error_handler = handler;
}

EventListenerRegistration PusherEventService::register_listener(std::shared_ptr<IEventListener> listener) {
    return cache_registration(EventListenerRegistration::RegistrationListenerConfiguration(listener));
}

EventListenerRegistration PusherEventService::register_listener_with_matcher(std::shared_ptr<IEventListener> listener,
                                                                             std::function<bool(
                                                                                     models::EventType)> matcher) {
    return cache_registration(EventListenerRegistration::RegistrationListenerConfiguration(listener)
                                      .with_matcher(matcher));
}

EventListenerRegistration
PusherEventService::register_listener_including_types(std::shared_ptr<IEventListener> listener,
                                                      const std::vector<models::EventType>& types) {
    return cache_registration(EventListenerRegistration::RegistrationListenerConfiguration(listener)
                                      .with_allowed_events(types));
}

EventListenerRegistration
PusherEventService::register_listener_excluding_types(std::shared_ptr<IEventListener> listener,
                                                      const std::vector<models::EventType>& types) {
    return cache_registration(EventListenerRegistration::RegistrationListenerConfiguration(listener)
                                      .with_ignored_events(types));
}

EventListenerRegistration&
PusherEventService::cache_registration(EventListenerRegistration::RegistrationListenerConfiguration configuration) {
    // Check if a registration for the listener already exists
    for (auto& r : listeners) {
        if (&r->get_listener() == &configuration.get_listener()) {
            return *r;
        }
    }

    std::unique_ptr<EventListenerRegistration> registration = configuration.create();
    EventListenerRegistration& ref = *registration;
    listeners.push_back(std::move(registration));

    return ref;
}

void PusherEventService::unregister_listener(IEventListener& listener) {
    // Finds the first registration that matches
    auto loc = std::find_if(listeners.begin(),
                            listeners.end(),
                            [&listener](const std::unique_ptr<EventListenerRegistration>& r) {
                                return &r->get_listener() == &listener;
                            });

    if (loc != listeners.end()) {
        listeners.erase(loc);
    }
}

void PusherEventService::subscribe_to_app(int app) {
    subscribe(AppChannel(platform.value(), app).channel());
}

void PusherEventService::unsubscribe_to_app(int app) {
    unsubscribe(AppChannel(platform.value(), app).channel());
}

bool PusherEventService::is_subscribed_to_app(int app) {
    return pusher_client->is_subscribed(AppChannel(platform.value(), app).channel());
}

void PusherEventService::subscribe_to_player(int app, const std::string& player) {
    subscribe(PlayerChannel(platform.value(), app, player).channel());
}

void PusherEventService::unsubscribe_to_player(int app, const std::string& player) {
    unsubscribe(PlayerChannel(platform.value(), app, player).channel());
}

bool PusherEventService::is_subscribed_to_player(int app, const std::string& player) {
    return pusher_client->is_subscribed(PlayerChannel(platform.value(), app, player).channel());
}

void PusherEventService::subscribe_to_token(const std::string& token) {
    subscribe(TokenChannel(platform.value(), token).channel());
}

void PusherEventService::unsubscribe_to_token(const std::string& token) {
    unsubscribe(TokenChannel(platform.value(), token).channel());
}

bool PusherEventService::is_subscribed_to_token(const std::string& token) {
    return pusher_client->is_subscribed(TokenChannel(platform.value(), token).channel());
}

void PusherEventService::subscribe_to_wallet(const std::string& wallet) {
    subscribe(WalletChannel(platform.value(), wallet).channel());
}

void PusherEventService::unsubscribe_to_wallet(const std::string& wallet) {
    unsubscribe(WalletChannel(platform.value(), wallet).channel());
}

bool PusherEventService::is_subscribed_to_wallet(const std::string& wallet) {
    return pusher_client->is_subscribed(WalletChannel(platform.value(), wallet).channel());
}

void PusherEventService::subscribe(const std::string& channel) {
    if (pusher_client == nullptr || pusher_client->is_subscribed_or_pending(channel)) {
        return;
    }

    pusher_client->subscribe(channel);
    bind(channel);
}

void PusherEventService::unsubscribe(const std::string& channel) {
    if (pusher_client == nullptr || !pusher_client->is_subscribed(channel)) {
        return;
    }

    pusher_client->unsubscribe(channel);
}

void PusherEventService::bind(const std::string& channel) {
    for (auto& def : EventTypeDef::filter_by_channel_types({channel})) {
        pusher_client->bind(def.get_key(), listener);
    }
}

std::unique_ptr<PusherEventService> PusherEventServiceBuilder::build() {
    if (m_ws_client == nullptr) {
        throw std::runtime_error("Websocket client was not assigned before building PusherEventService");
    }

    return m_platform.has_value()
           ? std::unique_ptr<PusherEventService>(
                    new PusherEventService(std::move(m_ws_client),
                                           m_platform.value()))
           : std::unique_ptr<PusherEventService>(
                    new PusherEventService(std::move(m_ws_client)));
}

PusherEventServiceBuilder& PusherEventServiceBuilder::platform(const models::Platform& platform) {
    m_platform = platform;
    return *this;
}

PusherEventServiceBuilder&
PusherEventServiceBuilder::ws_client(std::unique_ptr<websockets::IWebsocketClient> ws_client) {
    m_ws_client = std::move(ws_client);
    return *this;
}

PusherEventService::PusherEventListener::PusherEventListener(PusherEventService& service) : service(&service) {
}

void PusherEventService::PusherEventListener::on_event(const pusher::PusherEvent& event) {
    const std::string& key = event.get_event_name().has_value()
                             ? event.get_event_name().value()
                             : std::string();
    const std::string& channel = event.get_channel_name().has_value()
                                 ? event.get_channel_name().value()
                                 : std::string();
    const std::string& message = event.get_data().has_value()
                                 ? event.get_data().value()
                                 : std::string();

    // TODO: Log that event was received in logger if implemented.

    if (service->listeners.empty()) {
        // TODO: Log that no listeners were registered when event was received.
        return;
    }

    EventTypeDef def = EventTypeDef::get_from_key(key);
    if (def.get_type() == models::EventType::UNKNOWN) {
        // TODO: Log that an unknown event was received.
        return;
    }

    models::NotificationEvent notification_event(def.get_type(), channel, message);

    for (auto& registration : service->listeners) {
        if (registration->get_matcher()(notification_event.get_type())) {
            registration->get_listener().notification_received(notification_event);
        }
    }
}

}
