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

/* This header file contains the host names for Enjin networks.
 */

#ifndef ENJINCPPSDK_ENJINHOSTS_HPP
#define ENJINCPPSDK_ENJINHOSTS_HPP

namespace enjin::sdk {

/// \brief The URI for the kovan Enjin Cloud.
static constexpr char KOVAN[] = "https://kovan.cloud.enjin.io";

/// \brief The URI for the main Enjin Cloud.
static constexpr char MAIN_NET[] = "https://cloud.enjin.io";

/// \brief The URI for the JumpNet network.
static constexpr char JUMP_NET[] = "https://jumpnet.cloud.enjin.io";

}

#endif //ENJINCPPSDK_ENJINHOSTS_HPP
