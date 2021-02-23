#ifndef ENJINCPPSDK_IEVENTSERVICE_HPP
#define ENJINCPPSDK_IEVENTSERVICE_HPP

#include "enjinsdk/EventListenerRegistration.hpp"
#include "enjinsdk/models/Platform.hpp"
#include <functional>
#include <string>
#include <vector>

namespace enjin::sdk::events {

/// \brief Event service interface for subscribing to and registering for events from the Enjin Cloud.
class IEventService {
public:
    /// \brief Default destructor.
    virtual ~IEventService() = default;

    /// \brief Starts this service.
    virtual void start() = 0;

    /// \brief Starts this service with the provided platform details.
    /// \param platform The platform details.
    virtual void start(models::Platform platform) = 0;

    /// \brief Shuts down this service.
    virtual void shutdown() = 0;

    /// \brief Determines if this service is connected for receiving events.
    /// \return Whether this service is connected.
    virtual bool is_connected() = 0;

    /// \brief Determines if the the listener is registered to this service.
    /// \param listener The listener.
    /// \return Whether the listener is registered.
    virtual bool is_registered(IEventListener& listener) = 0;

    /// \brief Sets a handler for when the service connects to the server.
    /// \param handler The handler.
    virtual void set_connected_handler(const std::function<void()>& handler) = 0;

    /// \brief Sets a handler for when the service disconnects from the server.
    /// \param handler The handler.
    virtual void set_disconnected_handler(const std::function<void()>& handler) = 0;

    /// \brief Sets a handler for when the service encounters an error.
    /// \param handler The handler.
    virtual void set_error_handler(const std::function<void(const std::exception& e)>& handler) = 0;

    /// \brief Registers a event listener and provides the registration for it.
    /// \param listener The shared listener.
    /// \return The registration.
    virtual EventListenerRegistration register_listener(std::shared_ptr<IEventListener> listener) = 0;

    /// \brief Registers a event listener with a function for event matcher and provides the registration for it.
    /// \param listener The shared listener.
    /// \param matcher The event matcher.
    /// \return The registration.
    virtual EventListenerRegistration
    register_listener_with_matcher(std::shared_ptr<IEventListener> listener,
                                   std::function<bool(models::EventType)> matcher) = 0;

    /// \brief Registers a event listener with event types to allow and provides the registration for it.
    /// \param listener The shared listener.
    /// \param types The event types to allow.
    /// \return The registration.
    virtual EventListenerRegistration
    register_listener_including_types(std::shared_ptr<IEventListener> listener,
                                      const std::vector<models::EventType>& types) = 0;

    /// \brief Registers a event listener with event types to ignore and provides the registration for it.
    /// \param listener The shared listener.
    /// \param types The event types to ignore.
    /// \return The registration.
    virtual EventListenerRegistration
    register_listener_excluding_types(std::shared_ptr<IEventListener> listener,
                                      const std::vector<models::EventType>& types) = 0;

    /// \brief Unregisters the event listener from this service.
    /// \param listener The listener.
    virtual void unregister_listener(IEventListener& listener) = 0;

    /// \brief Opens a channel for the specified project, allowing listeners to receive events for it.
    /// \param project The project ID.
    virtual void subscribe_to_project(int project) = 0;

    /// \brief Closes a channel for the specified project, preventing listeners from receiving events for it.
    /// \param project The project ID.
    virtual void unsubscribe_to_project(int project) = 0;

    /// \brief Determines if this service is subscribed to the specified channel.
    /// \param project The project ID.
    /// \return Whether this service is subscribed to the channel.
    virtual bool is_subscribed_to_project(int project) = 0;

    /// \brief Opens a channel for the specified player, allowing listeners to receive events for it.
    /// \param project The project ID.
    /// \param player The player ID.
    virtual void subscribe_to_player(int project, const std::string& player) = 0;

    /// \brief Closes a channel for the specified player, preventing listeners from receiving events for it.
    /// \param project The project ID.
    /// \param player The player ID.
    virtual void unsubscribe_to_player(int project, const std::string& player) = 0;

    /// \brief Determines if this service is subscribed to the specified channel.
    /// \param project The project ID.
    /// \param player The player ID.
    /// \return Whether this service is subscribed to the channel.
    virtual bool is_subscribed_to_player(int project, const std::string& player) = 0;

    /// \brief Opens a channel for the specified asset, allowing listeners to receive events for it.
    /// \param asset The asset ID.
    virtual void subscribe_to_asset(const std::string& asset) = 0;

    /// \brief Closes a channel for the specified asset, preventing listeners from receiving events for it.
    /// \param asset The asset ID.
    virtual void unsubscribe_to_asset(const std::string& asset) = 0;

    /// \brief Determines if this service is subscribed to the specified channel.
    /// \param asset The asset ID.
    /// \return Whether this service is subscribed to the channel.
    virtual bool is_subscribed_to_asset(const std::string& asset) = 0;

    /// \brief Opens a channel for the specified wallet, allowing listeners to receive events for it.
    /// \param wallet The wallet's address.
    virtual void subscribe_to_wallet(const std::string& wallet) = 0;

    /// \brief Closes a channel for the specified wallet, preventing listeners from receiving events for it.
    /// \param wallet The wallet's address.
    virtual void unsubscribe_to_wallet(const std::string& wallet) = 0;

    /// \brief Determines if this service is subscribed to the specified channel.
    /// \param wallet The address.
    /// \return Whether this service is subscribed to the channel.
    virtual bool is_subscribed_to_wallet(const std::string& wallet) = 0;
};

}

#endif //ENJINCPPSDK_IEVENTSERVICE_HPP
