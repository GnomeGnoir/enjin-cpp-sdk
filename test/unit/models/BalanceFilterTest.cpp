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
#include "enjinsdk/models/BalanceFilter.hpp"
#include <string>
#include <vector>

using namespace enjin::sdk::models;
using namespace enjin::test::suites;

class BalanceFilterTest : public JsonTestSuite,
                          public testing::Test {
public:
    BalanceFilter class_under_test;

    constexpr static char POPULATED_JSON_OBJECT[] =
            R"({"and":[],"or":[],"projectUuid":"1","projectUuid_in":[],"assetId":"1","assetId_in":[],"wallet":"1","wallet_in":[],"value":1,"value_is":"GREATER_THAN"})";

    static BalanceFilter create_default_filter() {
        return BalanceFilter().set_and(std::vector<BalanceFilter>())
                              .set_or(std::vector<BalanceFilter>())
                              .set_project_uuid("1")
                              .set_project_uuid_in(std::vector<std::string>())
                              .set_asset_id("1")
                              .set_asset_id_in(std::vector<std::string>())
                              .set_wallet("1")
                              .set_wallet_in(std::vector<std::string>())
                              .set_value(1)
                              .set_value_is(Operator::GREATER_THAN);
    }
};

TEST_F(BalanceFilterTest, SerializeNoSetFieldsReturnsEmptyJsonObject) {
    // Arrange
    const std::string expected(EMPTY_JSON_OBJECT);

    // Act
    std::string actual = class_under_test.serialize();

    // Assert
    ASSERT_EQ(expected, actual);
}

TEST_F(BalanceFilterTest, SerializeSetFieldsReturnsExpectedJsonObject) {
    // Arrange
    const std::string expected(POPULATED_JSON_OBJECT);
    class_under_test.set_and(std::vector<BalanceFilter>())
                    .set_or(std::vector<BalanceFilter>())
                    .set_project_uuid("1")
                    .set_project_uuid_in(std::vector<std::string>())
                    .set_asset_id("1")
                    .set_asset_id_in(std::vector<std::string>())
                    .set_wallet("1")
                    .set_wallet_in(std::vector<std::string>())
                    .set_value(1)
                    .set_value_is(Operator::GREATER_THAN);

    // Act
    std::string actual = class_under_test.serialize();

    // Assert
    ASSERT_EQ(expected, actual);
}

TEST_F(BalanceFilterTest, EqualityNeitherSideIsPopulatedReturnsTrue) {
    // Arrange
    BalanceFilter lhs;
    BalanceFilter rhs;

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(BalanceFilterTest, EqualityBothSidesArePopulatedReturnsTrue) {
    // Arrange
    BalanceFilter lhs = create_default_filter();
    BalanceFilter rhs = create_default_filter();

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(BalanceFilterTest, EqualityLeftSideIsPopulatedReturnsFalse) {
    // Arrange
    BalanceFilter lhs = create_default_filter();
    BalanceFilter rhs;

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(BalanceFilterTest, EqualityRightSideIsPopulatedReturnsFalse) {
    // Arrange
    BalanceFilter lhs;
    BalanceFilter rhs = create_default_filter();

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_FALSE(actual);
}
