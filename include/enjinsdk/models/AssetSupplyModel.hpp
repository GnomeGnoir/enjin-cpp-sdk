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

#ifndef ENJINCPPSDK_ASSETSUPPLYMODEL_HPP
#define ENJINCPPSDK_ASSETSUPPLYMODEL_HPP

namespace enjin::sdk::models {

/// \brief Values used to specify the supply model for a asset.
enum class AssetSupplyModel {
    UNKNOWN, ///< SDK value for unknown values from the platform.
    FIXED,
    SETTABLE,
    INFINITE,
    COLLAPSING,
    ANNUAL_VALUE,
    ANNUAL_PERCENTAGE,
};

}

#endif //ENJINCPPSDK_ASSETSUPPLYMODEL_HPP
