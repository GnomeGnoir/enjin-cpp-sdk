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
#include "enjinsdk/models/PusherChannels.hpp"
#include <string>

using namespace enjin::sdk::models;
using namespace enjin::test::suites;

class PusherChannelsTest : public JsonTestSuite,
                           public testing::Test {
public:
    PusherChannels class_under_test;

    constexpr static char POPULATED_JSON_OBJECT[] =
            R"({"project":"1","player":"1","asset":"1","wallet":"1"})";
};

TEST_F(PusherChannelsTest, DeserializeEmptyStringFieldsDoNotHaveValues) {
    // Arrange
    const std::string json;

    // Act
    class_under_test.deserialize(json);

    // Assert
    EXPECT_FALSE(class_under_test.get_project().has_value());
    EXPECT_FALSE(class_under_test.get_player().has_value());
    EXPECT_FALSE(class_under_test.get_asset().has_value());
    EXPECT_FALSE(class_under_test.get_wallet().has_value());
}

TEST_F(PusherChannelsTest, DeserializeEmptyJsonObjectFieldsDoNotHaveValues) {
    // Arrange
    const std::string json(EMPTY_JSON_OBJECT);

    // Act
    class_under_test.deserialize(json);

    // Assert
    EXPECT_FALSE(class_under_test.get_project().has_value());
    EXPECT_FALSE(class_under_test.get_player().has_value());
    EXPECT_FALSE(class_under_test.get_asset().has_value());
    EXPECT_FALSE(class_under_test.get_wallet().has_value());
}

TEST_F(PusherChannelsTest, DeserializePopulatedJsonObjectFieldsHaveExpectedValues) {
    // Arrange
    const std::string expected_string("1");
    const std::string json(POPULATED_JSON_OBJECT);

    // Act
    class_under_test.deserialize(json);

    // Assert
    EXPECT_EQ(expected_string, class_under_test.get_project().value());
    EXPECT_EQ(expected_string, class_under_test.get_player().value());
    EXPECT_EQ(expected_string, class_under_test.get_asset().value());
    EXPECT_EQ(expected_string, class_under_test.get_wallet().value());
}

TEST_F(PusherChannelsTest, EqualityNeitherSideIsPopulatedReturnsTrue) {
    // Arrange
    PusherChannels lhs;
    PusherChannels rhs;

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(PusherChannelsTest, EqualityBothSidesArePopulatedReturnsTrue) {
    // Arrange
    PusherChannels lhs;
    PusherChannels rhs;
    lhs.deserialize(POPULATED_JSON_OBJECT);
    rhs.deserialize(POPULATED_JSON_OBJECT);

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(PusherChannelsTest, EqualityLeftSideIsPopulatedReturnsFalse) {
    // Arrange
    PusherChannels lhs;
    PusherChannels rhs;
    lhs.deserialize(POPULATED_JSON_OBJECT);

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(PusherChannelsTest, EqualityRightSideIsPopulatedReturnsFalse) {
    // Arrange
    PusherChannels lhs;
    PusherChannels rhs;
    rhs.deserialize(POPULATED_JSON_OBJECT);

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_FALSE(actual);
}
