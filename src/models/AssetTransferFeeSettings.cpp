#include "enjinsdk/models/AssetTransferFeeSettings.hpp"

#include "EnumUtils.hpp"
#include "RapidJsonUtils.hpp"

namespace enjin::sdk::models {

void AssetTransferFeeSettings::deserialize(const std::string& json) {
    rapidjson::Document document;
    document.Parse(json.c_str());
    if (document.IsObject()) {
        if (document.HasMember(TYPE_KEY) && document[TYPE_KEY].IsString()) {
            type.emplace(utils::deserialize_asset_transfer_fee_type(document[TYPE_KEY].GetString()));
        }
        if (document.HasMember(ASSET_ID_KEY) && document[ASSET_ID_KEY].IsString()) {
            asset_id.emplace(document[ASSET_ID_KEY].GetString());
        }
        if (document.HasMember(VALUE_KEY) && document[VALUE_KEY].IsString()) {
            value.emplace(document[VALUE_KEY].GetString());
        }
    }
}

const std::optional<AssetTransferFeeType>& AssetTransferFeeSettings::get_type() const {
    return type;
}

const std::optional<std::string>& AssetTransferFeeSettings::get_asset_id() const {
    return asset_id;
}

const std::optional<std::string>& AssetTransferFeeSettings::get_value() const {
    return value;
}

bool AssetTransferFeeSettings::operator==(const AssetTransferFeeSettings& rhs) const {
    return type == rhs.type &&
           asset_id == rhs.asset_id &&
           value == rhs.value;
}

bool AssetTransferFeeSettings::operator!=(const AssetTransferFeeSettings& rhs) const {
    return !(rhs == *this);
}

std::string AssetTransferFeeSettingsInput::serialize() {
    rapidjson::Document document(rapidjson::kObjectType);

    if (type.has_value()) {
        utils::set_string_member(document, TYPE_KEY, utils::serialize_asset_transfer_fee_type(type.value()));
    }
    if (asset_id.has_value()) {
        utils::set_string_member(document, ASSET_ID_KEY, asset_id.value());
    }
    if (value.has_value()) {
        utils::set_string_member(document, VALUE_KEY, value.value());
    }

    return utils::document_to_string(document);
}

AssetTransferFeeSettingsInput& AssetTransferFeeSettingsInput::set_type(AssetTransferFeeType type) {
    AssetTransferFeeSettingsInput::type = type;
    return *this;
}

AssetTransferFeeSettingsInput& AssetTransferFeeSettingsInput::set_asset_id(const std::string& asset_id) {
    AssetTransferFeeSettingsInput::asset_id = asset_id;
    return *this;
}

AssetTransferFeeSettingsInput& AssetTransferFeeSettingsInput::set_value(const std::string& value) {
    AssetTransferFeeSettingsInput::value = value;
    return *this;
}

bool AssetTransferFeeSettingsInput::operator==(const AssetTransferFeeSettingsInput& rhs) const {
    return static_cast<const AssetTransferFeeSettings&>(*this) ==
           static_cast<const AssetTransferFeeSettings&>(rhs);
}

bool AssetTransferFeeSettingsInput::operator!=(const AssetTransferFeeSettingsInput& rhs) const {
    return !(rhs == *this);
}

}