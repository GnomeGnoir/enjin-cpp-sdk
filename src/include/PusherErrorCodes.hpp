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

#ifndef ENJINCPPSDK_PUSHERERRORCODES_HPP
#define ENJINCPPSDK_PUSHERERRORCODES_HPP

namespace enjin::pusher {

/// \brief Error codes that may be received from Pusher.
enum class PusherErrorCodes : int {
    UNKNOWN = 0, ///< \brief A catch all error code.
    SUBSCRIPTION_ERROR = 5003,
};

}

#endif //ENJINCPPSDK_PUSHERERRORCODES_HPP
