/* Copyright 2021 Enjin Pte. Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ENJINCPPSDK_EVENTLISTENERREGISTRATION_HPP
#define ENJINCPPSDK_EVENTLISTENERREGISTRATION_HPP

#include "enjinsdk_export.h"
#include "enjinsdk/IEventListener.hpp"
#include "enjinsdk/models/EventType.hpp"
#include <functional>
#include <memory>

namespace enjin::sdk::events {

/// \brief Registration wrapper for a IEventListener.
class ENJINSDK_EXPORT EventListenerRegistration {
public:
    /// \brief Configuration class for building an EventListenerRegistration. To be used internally.
    class ENJINSDK_EXPORT RegistrationListenerConfiguration {
    public:
        RegistrationListenerConfiguration() = delete;

        /// \brief Constructs a configuration builder for a registration.
        /// \param listener The listener that the registration will receive.
        explicit RegistrationListenerConfiguration(const std::shared_ptr<IEventListener>& listener);

        /// \brief Default destructor.
        ~RegistrationListenerConfiguration() = default;

        /// \brief Sets the matcher to be used for the registration.
        /// \param matcher The matcher.
        /// \return This for chaining.
        RegistrationListenerConfiguration& with_matcher(const std::function<bool(models::EventType)>& matcher);

        /// \brief Sets the matcher to be used for the registration that allows the passed event types.
        /// \param types The event types to match.
        /// \return This for chaining.
        RegistrationListenerConfiguration& with_allowed_events(const std::vector<models::EventType>& types);

        /// \brief Sets the matcher to be used for the registration that ignore the passed event types.
        /// \param types The event types to not match.
        /// \return This for chaining.
        RegistrationListenerConfiguration& with_ignored_events(const std::vector<models::EventType>& types);

        /// \brief Creates the registration and provides the unique pointer for it.
        /// \return The unique pointer for the registration.
        [[nodiscard]] EventListenerRegistration create();

        /// \brief Returns a reference to the listener.
        /// \return The reference to the listener.
        [[nodiscard]] const IEventListener& get_listener() const;

    private:
        std::shared_ptr<IEventListener> listener;
        std::function<bool(models::EventType)> matcher = ALLOW_ALL_MATCHER;
    };

    EventListenerRegistration() = delete;

    /// \brief Default destructor.
    ~EventListenerRegistration() = default;

    /// \brief Returns a reference to the listener.
    /// \return The listener.
    [[nodiscard]] IEventListener& get_listener() const;

    /// \brief Returns the event type matcher associated with listener.
    /// \return The matcher.
    [[nodiscard]] const std::function<bool(models::EventType)>& get_matcher() const;

    /// \brief A matcher that returns true for any event type.
    inline static std::function<bool(models::EventType)> const ALLOW_ALL_MATCHER = [](models::EventType) {
        return true;
    };

protected:
    /// \brief Constructs the registration with the given listener and an allow all matcher.
    /// \param listener The listener.
    explicit EventListenerRegistration(const std::shared_ptr<IEventListener>& listener);

    /// \brief Constructs the registration with the given listener and matcher.
    /// \param listener The listener.
    /// \param matcher The matcher.
    EventListenerRegistration(const std::shared_ptr<IEventListener>& listener,
                              const std::function<bool(models::EventType)>& matcher);

private:
    std::shared_ptr<IEventListener> listener;
    std::function<bool(models::EventType)> matcher;
};

}

#endif //ENJINCPPSDK_EVENTLISTENERREGISTRATION_HPP
