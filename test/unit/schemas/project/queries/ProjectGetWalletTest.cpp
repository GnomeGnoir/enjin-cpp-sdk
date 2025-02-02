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
#include "WalletFragmentArgumentsTestSuite.hpp"
#include "enjinsdk/project/GetWallet.hpp"
#include "gtest/gtest.h"
#include <string>

using namespace enjin::sdk::project;
using namespace enjin::test::suites;

class ProjectGetWalletTest : public WalletFragmentArgumentsTestSuite<GetWallet>,
                             public JsonTestSuite,
                             public testing::Test {
public:
    GetWallet class_under_test;

    constexpr static char POPULATED_JSON_OBJECT[] =
            R"({"userId":"1","ethAddress":"1"})";

    static GetWallet create_default_request() {
        GetWallet request = GetWallet()
                .set_user_id("1")
                .set_eth_address("1");
        set_wallet_fragment_arguments(request);
        return request;
    }
};

TEST_F(ProjectGetWalletTest, SerializeNoSetFieldsReturnsEmptyJsonObject) {
    // Arrange
    const std::string expected(EMPTY_JSON_OBJECT);

    // Act
    std::string actual = class_under_test.serialize();

    // Assert
    ASSERT_EQ(expected, actual);
}

TEST_F(ProjectGetWalletTest, SerializeSetFieldsReturnsExpectedJsonObject) {
    // Arrange
    const std::string expected(POPULATED_JSON_OBJECT);
    class_under_test.set_user_id("1")
                    .set_eth_address("1");

    // Act
    std::string actual = class_under_test.serialize();

    // Assert
    ASSERT_EQ(expected, actual);
}

TEST_F(ProjectGetWalletTest, EqualityNeitherSideIsPopulatedReturnsTrue) {
    // Arrange
    GetWallet lhs;
    GetWallet rhs;

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(ProjectGetWalletTest, EqualityBothSidesArePopulatedReturnsTrue) {
    // Arrange
    GetWallet lhs = create_default_request();
    GetWallet rhs = create_default_request();

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(ProjectGetWalletTest, EqualityLeftSideIsPopulatedReturnsFalse) {
    // Arrange
    GetWallet lhs = create_default_request();
    GetWallet rhs;

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(ProjectGetWalletTest, EqualityRightSideIsPopulatedReturnsFalse) {
    // Arrange
    GetWallet lhs;
    GetWallet rhs = create_default_request();

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_FALSE(actual);
}
