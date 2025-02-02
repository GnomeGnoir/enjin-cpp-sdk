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

#include "enjinsdk/project/SetWhitelisted.hpp"

#include "EnumUtils.hpp"
#include "RapidJsonUtils.hpp"

namespace enjin::sdk::project {

SetWhitelisted::SetWhitelisted() : graphql::AbstractGraphqlRequest("enjin.sdk.project.SetWhitelisted") {
}

std::string SetWhitelisted::serialize() const {
    rapidjson::Document document(rapidjson::kObjectType);
    utils::join_serialized_object_to_document(document, ProjectTransactionRequestArguments::serialize());

    if (asset_id.has_value()) {
        utils::set_string_member(document, "assetId", asset_id.value());
    }
    if (account_address.has_value()) {
        utils::set_string_member(document, "accountAddress", account_address.value());
    }
    if (whitelisted.has_value()) {
        utils::set_string_member(document, "whitelisted", utils::serialize_whitelisted(whitelisted.value()));
    }
    if (whitelisted_address.has_value()) {
        utils::set_string_member(document, "whitelistedAddress", whitelisted_address.value());
    }
    if (on.has_value()) {
        utils::set_boolean_member(document, "on", on.value());
    }

    return utils::document_to_string(document);
}

SetWhitelisted& SetWhitelisted::set_asset_id(const std::string& asset_id) {
    SetWhitelisted::asset_id = asset_id;
    return *this;
}

SetWhitelisted& SetWhitelisted::set_account_address(const std::string& account_address) {
    SetWhitelisted::account_address = account_address;
    return *this;
}

SetWhitelisted& SetWhitelisted::set_whitelisted(models::Whitelisted whitelisted) {
    SetWhitelisted::whitelisted = whitelisted;
    return *this;
}

SetWhitelisted& SetWhitelisted::set_whitelisted_address(const std::string& whitelisted_address) {
    SetWhitelisted::whitelisted_address = whitelisted_address;
    return *this;
}

SetWhitelisted& SetWhitelisted::set_on(bool on) {
    SetWhitelisted::on = on;
    return *this;
}

bool SetWhitelisted::operator==(const SetWhitelisted& rhs) const {
    return static_cast<const graphql::AbstractGraphqlRequest&>(*this) ==
           static_cast<const graphql::AbstractGraphqlRequest&>(rhs) &&
           static_cast<const ProjectTransactionRequestArguments<SetWhitelisted>&>(*this) ==
           static_cast<const ProjectTransactionRequestArguments<SetWhitelisted>&>(rhs) &&
           asset_id == rhs.asset_id &&
           account_address == rhs.account_address &&
           whitelisted == rhs.whitelisted &&
           whitelisted_address == rhs.whitelisted_address &&
           on == rhs.on;
}

bool SetWhitelisted::operator!=(const SetWhitelisted& rhs) const {
    return !(rhs == *this);
}

}
