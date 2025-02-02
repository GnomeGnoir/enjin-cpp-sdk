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

#ifndef ENJINCPPSDK_PLAYERGETWALLET_HPP
#define ENJINCPPSDK_PLAYERGETWALLET_HPP

#include "enjinsdk_export.h"
#include "enjinsdk/internal/AbstractGraphqlRequest.hpp"
#include "enjinsdk/shared/WalletFragmentArguments.hpp"
#include <string>

namespace enjin::sdk::player {

/// \brief Request for getting the player's wallet.
class ENJINSDK_EXPORT GetWallet : public graphql::AbstractGraphqlRequest,
                                  public shared::WalletFragmentArguments<GetWallet> {
public:
    /// \brief Default constructor.
    GetWallet();

    ~GetWallet() override = default;

    [[nodiscard]] std::string serialize() const override;

    bool operator==(const GetWallet& rhs) const;

    bool operator!=(const GetWallet& rhs) const;
};

}

namespace enjin::sdk::shared {

template ENJINSDK_EXPORT player::GetWallet&
AssetFragmentArguments<player::GetWallet>::set_asset_id_format(models::AssetIdFormat asset_id_format);

template ENJINSDK_EXPORT player::GetWallet& AssetFragmentArguments<player::GetWallet>::set_with_state_data();

template ENJINSDK_EXPORT player::GetWallet& AssetFragmentArguments<player::GetWallet>::set_with_config_data();

template ENJINSDK_EXPORT player::GetWallet& AssetFragmentArguments<player::GetWallet>::set_with_asset_blocks();

template ENJINSDK_EXPORT player::GetWallet& AssetFragmentArguments<player::GetWallet>::set_with_creator();

template ENJINSDK_EXPORT player::GetWallet& AssetFragmentArguments<player::GetWallet>::set_with_melt_details();

template ENJINSDK_EXPORT player::GetWallet& AssetFragmentArguments<player::GetWallet>::set_with_metadata_uri();

template ENJINSDK_EXPORT player::GetWallet& AssetFragmentArguments<player::GetWallet>::set_with_supply_details();

template ENJINSDK_EXPORT player::GetWallet& AssetFragmentArguments<player::GetWallet>::set_with_transfer_settings();

template ENJINSDK_EXPORT player::GetWallet& AssetFragmentArguments<player::GetWallet>::set_with_asset_variant_mode();

template ENJINSDK_EXPORT player::GetWallet& AssetFragmentArguments<player::GetWallet>::set_with_asset_variants();

template ENJINSDK_EXPORT player::GetWallet& AssetFragmentArguments<player::GetWallet>::set_with_variant_metadata();

template ENJINSDK_EXPORT player::GetWallet& WalletFragmentArguments<player::GetWallet>::set_with_assets_created();

}

#endif //ENJINCPPSDK_PLAYERGETWALLET_HPP
