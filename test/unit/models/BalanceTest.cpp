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
#include "enjinsdk/models/Balance.hpp"
#include <string>

using namespace enjin::sdk::models;
using namespace enjin::test::suites;

class BalanceTest : public JsonTestSuite,
                    public testing::Test {
public:
    Balance class_under_test;

    constexpr static char POPULATED_JSON_OBJECT[] =
            R"({"id":"1","index":"1","value":1,"project":{},"wallet":{}})";
};

TEST_F(BalanceTest, DeserializeEmptyStringFieldsDoNotHaveValues) {
    // Arrange
    const std::string json;

    // Act
    class_under_test.deserialize(json);

    // Assert
    EXPECT_FALSE(class_under_test.get_id().has_value());
    EXPECT_FALSE(class_under_test.get_index().has_value());
    EXPECT_FALSE(class_under_test.get_value().has_value());
    EXPECT_FALSE(class_under_test.get_project().has_value());
    EXPECT_FALSE(class_under_test.get_wallet().has_value());
}

TEST_F(BalanceTest, DeserializeEmptyJsonObjectFieldsDoNotHaveValues) {
    // Arrange
    const std::string json(EMPTY_JSON_OBJECT);

    // Act
    class_under_test.deserialize(json);

    // Assert
    EXPECT_FALSE(class_under_test.get_id().has_value());
    EXPECT_FALSE(class_under_test.get_index().has_value());
    EXPECT_FALSE(class_under_test.get_value().has_value());
    EXPECT_FALSE(class_under_test.get_project().has_value());
    EXPECT_FALSE(class_under_test.get_wallet().has_value());
}

TEST_F(BalanceTest, DeserializePopulatedJsonObjectFieldsHaveExpectedValues) {
    // Arrange
    const int expected_int = 1;
    const std::string expected_string("1");
    const Project expected_project;
    const Wallet expected_wallet;
    const std::string json(POPULATED_JSON_OBJECT);

    // Act
    class_under_test.deserialize(json);

    // Assert
    EXPECT_EQ(expected_string, class_under_test.get_id().value());
    EXPECT_EQ(expected_string, class_under_test.get_index().value());
    EXPECT_EQ(expected_int, class_under_test.get_value().value());
    EXPECT_EQ(expected_project, class_under_test.get_project().value());
    EXPECT_EQ(expected_wallet, class_under_test.get_wallet().value());
}

TEST_F(BalanceTest, EqualityNeitherSideIsPopulatedReturnsTrue) {
    // Arrange
    Balance lhs;
    Balance rhs;

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(BalanceTest, EqualityBothSidesArePopulatedReturnsTrue) {
    // Arrange
    Balance lhs;
    Balance rhs;
    lhs.deserialize(POPULATED_JSON_OBJECT);
    rhs.deserialize(POPULATED_JSON_OBJECT);

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(BalanceTest, EqualityLeftSideIsPopulatedReturnsFalse) {
    // Arrange
    Balance lhs;
    Balance rhs;
    lhs.deserialize(POPULATED_JSON_OBJECT);

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(BalanceTest, EqualityRightSideIsPopulatedReturnsFalse) {
    // Arrange
    Balance lhs;
    Balance rhs;
    rhs.deserialize(POPULATED_JSON_OBJECT);

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_FALSE(actual);
}
