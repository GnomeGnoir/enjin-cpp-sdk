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

#ifndef ENJINCPPSDK_ENUMUTILS_HPP
#define ENJINCPPSDK_ENUMUTILS_HPP

#include "enjinsdk_export.h"
#include "PusherConnectionState.hpp"
#include "enjinsdk/models/EventType.hpp"
#include "enjinsdk/models/RequestState.hpp"
#include "enjinsdk/models/RequestType.hpp"
#include "enjinsdk/models/SortDirection.hpp"
#include "enjinsdk/models/AssetField.hpp"
#include "enjinsdk/models/AssetIdFormat.hpp"
#include "enjinsdk/models/AssetIndexFormat.hpp"
#include "enjinsdk/models/AssetSupplyModel.hpp"
#include "enjinsdk/models/AssetTransferFeeType.hpp"
#include "enjinsdk/models/AssetTransferable.hpp"
#include "enjinsdk/models/AssetVariantMode.hpp"
#include "enjinsdk/models/Operator.hpp"
#include "enjinsdk/models/TransactionField.hpp"
#include "enjinsdk/models/Whitelisted.hpp"
#include <string>

namespace enjin::sdk::utils {

ENJINSDK_EXPORT
models::EventType deserialize_event_type(const std::string& s) noexcept;

ENJINSDK_EXPORT
models::RequestState deserialize_request_state(const std::string& s) noexcept;

ENJINSDK_EXPORT
models::RequestType deserialize_request_type(const std::string& s) noexcept;

ENJINSDK_EXPORT
models::AssetSupplyModel deserialize_asset_supply_model(const std::string& s) noexcept;

ENJINSDK_EXPORT
models::AssetTransferFeeType deserialize_asset_transfer_fee_type(const std::string& s) noexcept;

ENJINSDK_EXPORT
models::AssetTransferable deserialize_asset_transferable(const std::string& s) noexcept;

ENJINSDK_EXPORT
models::AssetVariantMode deserialize_asset_variant_mode(const std::string& s) noexcept;

ENJINSDK_EXPORT
std::string serialize_event_type(models::EventType v) noexcept;

ENJINSDK_EXPORT
std::string serialize_pusher_connection_state(pusher::PusherConnectionState v) noexcept;

ENJINSDK_EXPORT
std::string serialize_request_state(models::RequestState v) noexcept;

ENJINSDK_EXPORT
std::string serialize_request_type(models::RequestType v) noexcept;

ENJINSDK_EXPORT
std::string serialize_sort_direction(models::SortDirection v) noexcept;

ENJINSDK_EXPORT
std::string serialize_asset_field(models::AssetField v) noexcept;

ENJINSDK_EXPORT
std::string serialize_asset_id_format(models::AssetIdFormat v) noexcept;

ENJINSDK_EXPORT
std::string serialize_asset_index_format(models::AssetIndexFormat v) noexcept;

ENJINSDK_EXPORT
std::string serialize_asset_supply_model(models::AssetSupplyModel v) noexcept;

ENJINSDK_EXPORT
std::string serialize_asset_transfer_fee_type(models::AssetTransferFeeType v) noexcept;

ENJINSDK_EXPORT
std::string serialize_asset_transferable(models::AssetTransferable v) noexcept;

ENJINSDK_EXPORT
std::string serialize_asset_variant_mode(models::AssetVariantMode v) noexcept;

ENJINSDK_EXPORT
std::string serialize_operator(models::Operator v) noexcept;

ENJINSDK_EXPORT
std::string serialize_transaction_field(models::TransactionField v) noexcept;

ENJINSDK_EXPORT
std::string serialize_whitelisted(models::Whitelisted v) noexcept;

}

#endif //ENJINCPPSDK_ENUMUTILS_HPP
