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
#include "enjinsdk/models/Notifications.hpp"
#include <string>

using namespace enjin::sdk::models;
using namespace enjin::test::suites;

class NotificationsTest : public JsonTestSuite,
                          public testing::Test {
public:
    Notifications class_under_test;

    constexpr static char POPULATED_JSON_OBJECT[] =
            R"({"pusher":{}})";
};

TEST_F(NotificationsTest, DeserializeEmptyStringFieldsDoNotHaveValues) {
    // Arrange
    const std::string json;

    // Act
    class_under_test.deserialize(json);

    // Assert
    EXPECT_FALSE(class_under_test.get_pusher().has_value());
}

TEST_F(NotificationsTest, DeserializeEmptyJsonObjectFieldsDoNotHaveValues) {
    // Arrange
    const std::string json(EMPTY_JSON_OBJECT);

    // Act
    class_under_test.deserialize(json);

    // Assert
    EXPECT_FALSE(class_under_test.get_pusher().has_value());
}

TEST_F(NotificationsTest, DeserializePopulatedJsonObjectFieldsHaveExpectedValues) {
    // Arrange
    const Pusher expected_pusher;
    const std::string json(POPULATED_JSON_OBJECT);

    // Act
    class_under_test.deserialize(json);

    // Assert
    EXPECT_EQ(expected_pusher, class_under_test.get_pusher().value());
}

TEST_F(NotificationsTest, EqualityNeitherSideIsPopulatedReturnsTrue) {
    // Arrange
    Notifications lhs;
    Notifications rhs;

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(NotificationsTest, EqualityBothSidesArePopulatedReturnsTrue) {
    // Arrange
    Notifications lhs;
    Notifications rhs;
    lhs.deserialize(POPULATED_JSON_OBJECT);
    rhs.deserialize(POPULATED_JSON_OBJECT);

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(NotificationsTest, EqualityLeftSideIsPopulatedReturnsFalse) {
    // Arrange
    Notifications lhs;
    Notifications rhs;
    lhs.deserialize(POPULATED_JSON_OBJECT);

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(NotificationsTest, EqualityRightSideIsPopulatedReturnsFalse) {
    // Arrange
    Notifications lhs;
    Notifications rhs;
    rhs.deserialize(POPULATED_JSON_OBJECT);

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_FALSE(actual);
}
