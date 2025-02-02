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

#include "JsonTestSuite.hpp"
#include "TransactionFragmentArgumentsTestSuite.hpp"
#include "enjinsdk/player/AdvancedSendAsset.hpp"
#include "gtest/gtest.h"
#include <string>

using namespace enjin::sdk::models;
using namespace enjin::sdk::player;
using namespace enjin::test::suites;

class PlayerAdvancedSendAssetTest : public TransactionFragmentArgumentsTestSuite<AdvancedSendAsset>,
                                    public JsonTestSuite,
                                    public testing::Test {
public:
    AdvancedSendAsset class_under_test;

    constexpr static char POPULATED_JSON_OBJECT[] =
            R"({"transfers":[],"data":"1"})";

    static AdvancedSendAsset create_default_request() {
        AdvancedSendAsset request = AdvancedSendAsset()
                .set_transfers(std::vector<Transfer>())
                .set_data("1");
        set_transaction_fragment_arguments(request);
        return request;
    }
};

TEST_F(PlayerAdvancedSendAssetTest, SerializeNoSetFieldsReturnsEmptyJsonObject) {
    // Arrange
    const std::string expected(EMPTY_JSON_OBJECT);

    // Act
    std::string actual = class_under_test.serialize();

    // Assert
    ASSERT_EQ(expected, actual);
}

TEST_F(PlayerAdvancedSendAssetTest, SerializeSetFieldsReturnsExpectedJsonObject) {
    // Arrange
    const std::string expected(POPULATED_JSON_OBJECT);
    class_under_test.set_transfers(std::vector<Transfer>())
                    .set_data("1");

    // Act
    std::string actual = class_under_test.serialize();

    // Assert
    ASSERT_EQ(expected, actual);
}

TEST_F(PlayerAdvancedSendAssetTest, EqualityNeitherSideIsPopulatedReturnsTrue) {
    // Arrange
    AdvancedSendAsset lhs;
    AdvancedSendAsset rhs;

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(PlayerAdvancedSendAssetTest, EqualityBothSidesArePopulatedReturnsTrue) {
    // Arrange
    AdvancedSendAsset lhs = create_default_request();
    AdvancedSendAsset rhs = create_default_request();

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(PlayerAdvancedSendAssetTest, EqualityLeftSideIsPopulatedReturnsFalse) {
    // Arrange
    AdvancedSendAsset lhs = create_default_request();
    AdvancedSendAsset rhs;

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(PlayerAdvancedSendAssetTest, EqualityRightSideIsPopulatedReturnsFalse) {
    // Arrange
    AdvancedSendAsset lhs;
    AdvancedSendAsset rhs = create_default_request();

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_FALSE(actual);
}
