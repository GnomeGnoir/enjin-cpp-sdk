/* Copyright 2021 Enjin Pte Ltd.
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

#include "ProjectChannel.hpp"

#include "enjinsdk_utils/StringUtils.hpp"
#include <sstream>

namespace enjin::sdk::events {

ProjectChannel::ProjectChannel(const models::Platform& platform, int project_id)
        : platform(platform), project_id(project_id) {
}

std::string ProjectChannel::channel() const {
    std::stringstream ss;
    ss << "enjincloud."
       << utils::to_lower(platform.get_network().value())
       << ".project."
       << project_id;
    return ss.str();
}

}
