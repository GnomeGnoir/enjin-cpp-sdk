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

#include "enjinsdk/EventListenerRegistration.hpp"

#include <algorithm>

namespace enjin::sdk::events {

EventListenerRegistration::EventListenerRegistration(const std::shared_ptr<IEventListener>& listener)
        : EventListenerRegistration(listener, ALLOW_ALL_MATCHER) {
}

EventListenerRegistration::EventListenerRegistration(const std::shared_ptr<IEventListener>& listener,
                                                     const std::function<bool(models::EventType)>& matcher)
        : listener(listener),
          matcher(matcher) {
}

IEventListener& EventListenerRegistration::get_listener() const {
    return *listener;
}

const std::function<bool(models::EventType)>& EventListenerRegistration::get_matcher() const {
    return matcher;
}

EventListenerRegistration::RegistrationListenerConfiguration::RegistrationListenerConfiguration(
        const std::shared_ptr<IEventListener>& listener) : listener(listener) {
}

EventListenerRegistration::RegistrationListenerConfiguration&
EventListenerRegistration::RegistrationListenerConfiguration::with_matcher(
        const std::function<bool(models::EventType)>& matcher) {
    EventListenerRegistration::RegistrationListenerConfiguration::matcher = matcher;
    return *this;
}

EventListenerRegistration::RegistrationListenerConfiguration&
EventListenerRegistration::RegistrationListenerConfiguration::with_allowed_events(
        const std::vector<models::EventType>& types) {
    matcher = [types](models::EventType type) {
        return std::any_of(types.begin(), types.end(), [type](models::EventType t) {
            return t == type; // Any of the allowed events equal the type which occurred
        });
    };
    return *this;
}

EventListenerRegistration::RegistrationListenerConfiguration&
EventListenerRegistration::RegistrationListenerConfiguration::with_ignored_events(
        const std::vector<models::EventType>& types) {
    matcher = [types](models::EventType type) {
        return std::all_of(types.begin(), types.end(), [type](models::EventType t) {
            return t != type; // All of the ignored events do not equal the type which occurred
        });
    };
    return *this;
}

EventListenerRegistration
EventListenerRegistration::RegistrationListenerConfiguration::create() {
    return EventListenerRegistration(listener, matcher);
}

const IEventListener& EventListenerRegistration::RegistrationListenerConfiguration::get_listener() const {
    return *listener;
}

}
