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

#include "enjinsdk/internal/TransactionFragmentArgumentsImpl.hpp"

#include "EnumUtils.hpp"
#include "RapidJsonUtils.hpp"

namespace enjin::sdk::shared {

std::string TransactionFragmentArgumentsImpl::serialize() const {
    rapidjson::Document document(rapidjson::kObjectType);

    if (asset_id_format.has_value()) {
        utils::set_string_member(document,
                                 "assetIdFormat",
                                 utils::serialize_asset_id_format(asset_id_format.value()));
    }
    if (with_blockchain_data.has_value()) {
        utils::set_boolean_member(document, "withBlockchainData", with_blockchain_data.value());
    }
    if (with_meta.has_value()) {
        utils::set_boolean_member(document, "withMeta", with_meta.value());
    }
    if (with_encoded_data.has_value()) {
        utils::set_boolean_member(document, "withEncodedData", with_encoded_data.value());
    }
    if (with_asset_data.has_value()) {
        utils::set_boolean_member(document, "withAssetData", with_asset_data.value());
    }
    if (with_signed_txs.has_value()) {
        utils::set_boolean_member(document, "withSignedTxs", with_signed_txs.value());
    }
    if (with_error.has_value()) {
        utils::set_boolean_member(document, "withError", with_error.value());
    }
    if (with_nonce.has_value()) {
        utils::set_boolean_member(document, "withNonce", with_nonce.value());
    }
    if (with_state.has_value()) {
        utils::set_boolean_member(document, "withState", with_state.value());
    }
    if (with_receipt.has_value()) {
        utils::set_boolean_member(document, "withReceipt", with_receipt.value());
    }
    if (with_receipt_logs.has_value()) {
        utils::set_boolean_member(document, "withReceiptLogs", with_receipt_logs.value());
    }
    if (with_log_event.has_value()) {
        utils::set_boolean_member(document, "withLogEvent", with_log_event.value());
    }
    if (with_transaction_project_uuid.has_value()) {
        utils::set_boolean_member(document, "withTransactionProjectUuid", with_transaction_project_uuid.value());
    }

    return utils::document_to_string(document);
}

void TransactionFragmentArgumentsImpl::set_asset_id_format(models::AssetIdFormat asset_id_format) {
    TransactionFragmentArgumentsImpl::asset_id_format = asset_id_format;
}

void TransactionFragmentArgumentsImpl::set_with_blockchain_data() {
    with_blockchain_data = true;
}

void TransactionFragmentArgumentsImpl::set_with_meta() {
    with_meta = true;
}

void TransactionFragmentArgumentsImpl::set_with_encoded_data() {
    with_encoded_data = true;
}

void TransactionFragmentArgumentsImpl::set_with_asset_data() {
    with_asset_data = true;
}

void TransactionFragmentArgumentsImpl::set_with_signed_txs() {
    with_signed_txs = true;
}

void TransactionFragmentArgumentsImpl::set_with_error() {
    with_error = true;
}

void TransactionFragmentArgumentsImpl::set_with_nonce() {
    with_nonce = true;
}

void TransactionFragmentArgumentsImpl::set_with_state() {
    with_state = true;
}

void TransactionFragmentArgumentsImpl::set_with_receipt() {
    with_receipt = true;
}

void TransactionFragmentArgumentsImpl::set_with_receipt_logs() {
    with_receipt_logs = true;
}

void TransactionFragmentArgumentsImpl::set_with_log_event() {
    with_log_event = true;
}

void TransactionFragmentArgumentsImpl::set_with_transaction_project_uuid() {
    with_transaction_project_uuid = true;
}

bool TransactionFragmentArgumentsImpl::operator==(const TransactionFragmentArgumentsImpl& rhs) const {
    return asset_id_format == rhs.asset_id_format &&
           with_blockchain_data == rhs.with_blockchain_data &&
           with_meta == rhs.with_meta &&
           with_encoded_data == rhs.with_encoded_data &&
           with_asset_data == rhs.with_asset_data &&
           with_signed_txs == rhs.with_signed_txs &&
           with_error == rhs.with_error &&
           with_nonce == rhs.with_nonce &&
           with_state == rhs.with_state &&
           with_receipt == rhs.with_receipt &&
           with_receipt_logs == rhs.with_receipt_logs &&
           with_log_event == rhs.with_log_event &&
           with_transaction_project_uuid == rhs.with_transaction_project_uuid;
}

bool TransactionFragmentArgumentsImpl::operator!=(const TransactionFragmentArgumentsImpl& rhs) const {
    return !(rhs == *this);
}

}
