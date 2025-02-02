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

#ifndef ENJINCPPSDK_PLAYERGETPLAYER_HPP
#define ENJINCPPSDK_PLAYERGETPLAYER_HPP

#include "enjinsdk_export.h"
#include "enjinsdk/internal/AbstractGraphqlRequest.hpp"
#include "enjinsdk/shared/PlayerFragmentArguments.hpp"
#include <string>

namespace enjin::sdk::player {

/// \brief Request for getting information about the player.
class ENJINSDK_EXPORT GetPlayer : public graphql::AbstractGraphqlRequest,
                                  public shared::PlayerFragmentArguments<GetPlayer> {
public:
    /// \brief Default constructor.
    GetPlayer();

    ~GetPlayer() override = default;

    [[nodiscard]] std::string serialize() const override;

    bool operator==(const GetPlayer& rhs) const;

    bool operator!=(const GetPlayer& rhs) const;
};

}

namespace enjin::sdk::shared {

template ENJINSDK_EXPORT player::GetPlayer&
AssetFragmentArguments<player::GetPlayer>::set_asset_id_format(models::AssetIdFormat asset_id_format);

template ENJINSDK_EXPORT player::GetPlayer& AssetFragmentArguments<player::GetPlayer>::set_with_state_data();

template ENJINSDK_EXPORT player::GetPlayer& AssetFragmentArguments<player::GetPlayer>::set_with_config_data();

template ENJINSDK_EXPORT player::GetPlayer& AssetFragmentArguments<player::GetPlayer>::set_with_asset_blocks();

template ENJINSDK_EXPORT player::GetPlayer& AssetFragmentArguments<player::GetPlayer>::set_with_creator();

template ENJINSDK_EXPORT player::GetPlayer& AssetFragmentArguments<player::GetPlayer>::set_with_melt_details();

template ENJINSDK_EXPORT player::GetPlayer& AssetFragmentArguments<player::GetPlayer>::set_with_metadata_uri();

template ENJINSDK_EXPORT player::GetPlayer& AssetFragmentArguments<player::GetPlayer>::set_with_supply_details();

template ENJINSDK_EXPORT player::GetPlayer& AssetFragmentArguments<player::GetPlayer>::set_with_transfer_settings();

template ENJINSDK_EXPORT player::GetPlayer& AssetFragmentArguments<player::GetPlayer>::set_with_asset_variant_mode();

template ENJINSDK_EXPORT player::GetPlayer& AssetFragmentArguments<player::GetPlayer>::set_with_asset_variants();

template ENJINSDK_EXPORT player::GetPlayer& AssetFragmentArguments<player::GetPlayer>::set_with_variant_metadata();

template ENJINSDK_EXPORT player::GetPlayer& PlayerFragmentArguments<player::GetPlayer>::set_with_linking_info();

template ENJINSDK_EXPORT player::GetPlayer& PlayerFragmentArguments<player::GetPlayer>::set_qr_size(int size);

template ENJINSDK_EXPORT player::GetPlayer& PlayerFragmentArguments<player::GetPlayer>::set_with_wallet();

template ENJINSDK_EXPORT player::GetPlayer& WalletFragmentArguments<player::GetPlayer>::set_with_assets_created();

}

#endif //ENJINCPPSDK_PLAYERGETPLAYER_HPP
