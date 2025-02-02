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

#include "gtest/gtest.h"
#include "JsonTestSuite.hpp"
#include "enjinsdk/internal/AssetFragmentArgumentsImpl.hpp"
#include <string>

using namespace enjin::sdk::models;
using namespace enjin::sdk::shared;
using namespace enjin::test::suites;

class SharedAssetFragmentArgumentsImplTest : public JsonTestSuite,
                                             public testing::Test {
public:
    AssetFragmentArgumentsImpl class_under_test;

    constexpr static char POPULATED_JSON_OBJECT[] =
            R"({"assetIdFormat":"hex64","withStateData":true,"withConfigData":true,"withAssetBlocks":true,"withCreator":true,"withMeltDetails":true,"withMetadataURI":true,"withSupplyDetails":true,"withTransferSettings":true,"withAssetVariantMode":true,"withAssetVariants":true,"withVariantMetadata":true})";

    static AssetFragmentArgumentsImpl create_default_arguments() {
        AssetFragmentArgumentsImpl arguments;
        arguments.set_asset_id_format(AssetIdFormat::HEX64);
        arguments.set_with_state_data();
        arguments.set_with_config_data();
        arguments.set_with_asset_blocks();
        arguments.set_with_creator();
        arguments.set_with_melt_details();
        arguments.set_with_metadata_uri();
        arguments.set_with_supply_details();
        arguments.set_with_transfer_settings();
        arguments.set_with_asset_variant_mode();
        arguments.set_with_asset_variants();
        arguments.set_with_variant_metadata();
        return arguments;
    }
};

TEST_F(SharedAssetFragmentArgumentsImplTest, SerializeNoSetFieldsReturnsEmptyJsonObject) {
    // Arrange
    const std::string expected(EMPTY_JSON_OBJECT);

    // Act
    std::string actual = class_under_test.serialize();

    // Assert
    ASSERT_EQ(expected, actual);
}

TEST_F(SharedAssetFragmentArgumentsImplTest, SerializeSetFieldsReturnsExpectedJsonObject) {
    // Arrange
    const std::string expected(POPULATED_JSON_OBJECT);
    class_under_test.set_asset_id_format(AssetIdFormat::HEX64);
    class_under_test.set_with_state_data();
    class_under_test.set_with_config_data();
    class_under_test.set_with_asset_blocks();
    class_under_test.set_with_creator();
    class_under_test.set_with_melt_details();
    class_under_test.set_with_metadata_uri();
    class_under_test.set_with_supply_details();
    class_under_test.set_with_transfer_settings();
    class_under_test.set_with_asset_variant_mode();
    class_under_test.set_with_asset_variants();
    class_under_test.set_with_variant_metadata();

    // Act
    std::string actual = class_under_test.serialize();

    // Assert
    ASSERT_EQ(expected, actual);
}

TEST_F(SharedAssetFragmentArgumentsImplTest, EqualityNeitherSideIsPopulatedReturnsTrue) {
    // Arrange
    AssetFragmentArgumentsImpl lhs;
    AssetFragmentArgumentsImpl rhs;

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(SharedAssetFragmentArgumentsImplTest, EqualityBothSidesArePopulatedReturnsTrue) {
    // Arrange
    AssetFragmentArgumentsImpl lhs = create_default_arguments();
    AssetFragmentArgumentsImpl rhs = create_default_arguments();

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(SharedAssetFragmentArgumentsImplTest, EqualityLeftSideIsPopulatedReturnsFalse) {
    // Arrange
    AssetFragmentArgumentsImpl lhs = create_default_arguments();
    AssetFragmentArgumentsImpl rhs;

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(SharedAssetFragmentArgumentsImplTest, EqualityRightSideIsPopulatedReturnsFalse) {
    // Arrange
    AssetFragmentArgumentsImpl lhs;
    AssetFragmentArgumentsImpl rhs = create_default_arguments();

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_FALSE(actual);
}
