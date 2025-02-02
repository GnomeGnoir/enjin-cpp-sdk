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

#ifndef ENJINCPPSDK_BALANCE_HPP
#define ENJINCPPSDK_BALANCE_HPP

#include "enjinsdk_export.h"
#include "enjinsdk/IDeserializable.hpp"
#include "enjinsdk/models/Project.hpp"
#include "enjinsdk/models/Wallet.hpp"
#include <optional>
#include <string>

namespace enjin::sdk::models {

/// \brief Models a asset balance.
class ENJINSDK_EXPORT Balance : public serialization::IDeserializable {
public:
    /// \brief Default constructor.
    Balance() = default;

    ~Balance() override = default;

    void deserialize(const std::string& json) override;

    /// \brief Returns the asset ID for this balance.
    /// \return The asset ID.
    [[nodiscard]] const std::optional<std::string>& get_id() const;

    /// \brief Returns the asset index for this balance.
    /// \return The asset index.
    [[nodiscard]] const std::optional<std::string>& get_index() const;

    /// \brief Returns the amount of the asset in the balance.
    /// \return The amount of the asset.
    [[nodiscard]] const std::optional<int>& get_value() const;

    /// \brief Returns the project the asset of this balance belongs to.
    /// \return The project.
    [[nodiscard]] const std::optional<Project>& get_project() const;

    /// \brief Returns the wallet this balance belongs to.
    /// \return The wallet.
    [[nodiscard]] const std::optional<Wallet>& get_wallet() const;

    bool operator==(const Balance& rhs) const;

    bool operator!=(const Balance& rhs) const;

private:
    std::optional<std::string> id;
    std::optional<std::string> index;
    std::optional<int> value;
    std::optional<Project> project;
    std::optional<Wallet> wallet;

    constexpr static char ID_KEY[] = "id";
    constexpr static char INDEX_KEY[] = "index";
    constexpr static char VALUE_KEY[] = "value";
    constexpr static char PROJECT_KEY[] = "project";
    constexpr static char WALLET_KEY[] = "wallet";
};

}

#endif //ENJINCPPSDK_BALANCE_HPP
