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

#ifndef ENJINCPPSDK_SHAREDGETPLATFORM_HPP
#define ENJINCPPSDK_SHAREDGETPLATFORM_HPP

#include "enjinsdk_export.h"
#include "enjinsdk/internal/AbstractGraphqlRequest.hpp"
#include <optional>

namespace enjin::sdk::shared {

/// \brief Request for getting the platform details.
class ENJINSDK_EXPORT GetPlatform : public graphql::AbstractGraphqlRequest {
public:
    /// \brief Default constructor.
    GetPlatform();

    ~GetPlatform() override = default;

    [[nodiscard]] std::string serialize() const override;

    /// \brief Sets the request to include the contracts with the platform.
    /// \return This request for chaining.
    GetPlatform& set_with_contracts();

    /// Sets the request to include the notification drivers with the platform.
    /// \return This request for chaining.
    GetPlatform& set_with_notifications();

    bool operator==(const GetPlatform& rhs) const;

    bool operator!=(const GetPlatform& rhs) const;

private:
    std::optional<bool> with_contracts;
    std::optional<bool> with_notifications;
};

}

#endif //ENJINCPPSDK_SHAREDGETPLATFORM_HPP
