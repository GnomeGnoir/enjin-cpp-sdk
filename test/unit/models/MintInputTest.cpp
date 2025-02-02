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
#include "enjinsdk/models/MintInput.hpp"
#include <string>

using namespace enjin::sdk::models;
using namespace enjin::test::suites;

class MintInputTest : public JsonTestSuite,
                      public testing::Test {
public:
    MintInput class_under_test;

    constexpr static char POPULATED_JSON_OBJECT[] =
            R"({"to":"1","value":"1"})";

    static MintInput create_default_mint_input() {
        return MintInput().set_to("1")
                          .set_value("1");
    }
};

TEST_F(MintInputTest, SerializeNoSetFieldsReturnsEmptyJsonObject) {
    // Arrange
    const std::string expected(EMPTY_JSON_OBJECT);

    // Act
    std::string actual = class_under_test.serialize();

    // Assert
    ASSERT_EQ(expected, actual);
}

TEST_F(MintInputTest, SerializeSetFieldsReturnsExpectedJsonObject) {
    // Arrange
    const std::string expected(POPULATED_JSON_OBJECT);
    class_under_test.set_to("1")
                    .set_value("1");

    // Act
    std::string actual = class_under_test.serialize();

    // Assert
    ASSERT_EQ(expected, actual);
}

TEST_F(MintInputTest, EqualityNeitherSideIsPopulatedReturnsTrue) {
    // Arrange
    MintInput lhs;
    MintInput rhs;

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(MintInputTest, EqualityBothSidesArePopulatedReturnsTrue) {
    // Arrange
    MintInput lhs = create_default_mint_input();
    MintInput rhs = create_default_mint_input();

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(MintInputTest, EqualityLeftSideIsPopulatedReturnsFalse) {
    // Arrange
    MintInput lhs = create_default_mint_input();
    MintInput rhs;

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(MintInputTest, EqualityRightSideIsPopulatedReturnsFalse) {
    // Arrange
    MintInput lhs;
    MintInput rhs = create_default_mint_input();

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_FALSE(actual);
}
