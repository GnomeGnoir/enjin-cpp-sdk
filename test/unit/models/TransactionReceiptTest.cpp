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
#include "enjinsdk/models/TransactionReceipt.hpp"
#include <string>

using namespace enjin::sdk::models;
using namespace enjin::test::suites;

class TransactionReceiptTest : public JsonTestSuite,
                               public testing::Test {
public:
    TransactionReceipt class_under_test;

    constexpr static char POPULATED_JSON_OBJECT[] =
            R"({"blockHash":"1","blockNumber":1,"cumulativeGasUsed":1,"gasUsed":1,"from":"1","to":"1","transactionHash":"1","transactionIndex":1,"status":true,"logs":[]})";
};

TEST_F(TransactionReceiptTest, DeserializeEmptyStringFieldsDoNotHaveValues) {
    // Arrange
    const std::string json;

    // Act
    class_under_test.deserialize(json);

    // Assert
    EXPECT_FALSE(class_under_test.get_block_hash().has_value());
    EXPECT_FALSE(class_under_test.get_block_number().has_value());
    EXPECT_FALSE(class_under_test.get_cumulative_gas_used().has_value());
    EXPECT_FALSE(class_under_test.get_gas_used().has_value());
    EXPECT_FALSE(class_under_test.get_from().has_value());
    EXPECT_FALSE(class_under_test.get_to().has_value());
    EXPECT_FALSE(class_under_test.get_transaction_hash().has_value());
    EXPECT_FALSE(class_under_test.get_transaction_index().has_value());
    EXPECT_FALSE(class_under_test.get_status().has_value());
    EXPECT_FALSE(class_under_test.get_logs().has_value());
}

TEST_F(TransactionReceiptTest, DeserializeEmptyJsonObjectFieldsDoNotHaveValues) {
    // Arrange
    const std::string json(EMPTY_JSON_OBJECT);

    // Act
    class_under_test.deserialize(json);

    // Assert
    EXPECT_FALSE(class_under_test.get_block_hash().has_value());
    EXPECT_FALSE(class_under_test.get_block_number().has_value());
    EXPECT_FALSE(class_under_test.get_cumulative_gas_used().has_value());
    EXPECT_FALSE(class_under_test.get_gas_used().has_value());
    EXPECT_FALSE(class_under_test.get_from().has_value());
    EXPECT_FALSE(class_under_test.get_to().has_value());
    EXPECT_FALSE(class_under_test.get_transaction_hash().has_value());
    EXPECT_FALSE(class_under_test.get_transaction_index().has_value());
    EXPECT_FALSE(class_under_test.get_status().has_value());
    EXPECT_FALSE(class_under_test.get_logs().has_value());
}

TEST_F(TransactionReceiptTest, DeserializePopulatedJsonObjectFieldsHaveExpectedValues) {
    // Arrange
    const int expected_int = 1;
    const bool expected_bool = true;
    const std::string expected_string("1");
    const std::string json(POPULATED_JSON_OBJECT);

    // Act
    class_under_test.deserialize(json);

    // Assert
    EXPECT_EQ(expected_string, class_under_test.get_block_hash().value());
    EXPECT_EQ(expected_int, class_under_test.get_block_number().value());
    EXPECT_EQ(expected_int, class_under_test.get_cumulative_gas_used().value());
    EXPECT_EQ(expected_int, class_under_test.get_gas_used().value());
    EXPECT_EQ(expected_string, class_under_test.get_from().value());
    EXPECT_EQ(expected_string, class_under_test.get_to().value());
    EXPECT_EQ(expected_string, class_under_test.get_transaction_hash().value());
    EXPECT_EQ(expected_int, class_under_test.get_transaction_index().value());
    EXPECT_EQ(expected_bool, class_under_test.get_status().value());
    EXPECT_TRUE(class_under_test.get_logs().has_value());
}

TEST_F(TransactionReceiptTest, EqualityNeitherSideIsPopulatedReturnsTrue) {
    // Arrange
    TransactionReceipt lhs;
    TransactionReceipt rhs;

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(TransactionReceiptTest, EqualityBothSidesArePopulatedReturnsTrue) {
    // Arrange
    TransactionReceipt lhs;
    TransactionReceipt rhs;
    lhs.deserialize(POPULATED_JSON_OBJECT);
    rhs.deserialize(POPULATED_JSON_OBJECT);

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(TransactionReceiptTest, EqualityLeftSideIsPopulatedReturnsFalse) {
    // Arrange
    TransactionReceipt lhs;
    TransactionReceipt rhs;
    lhs.deserialize(POPULATED_JSON_OBJECT);

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(TransactionReceiptTest, EqualityRightSideIsPopulatedReturnsFalse) {
    // Arrange
    TransactionReceipt lhs;
    TransactionReceipt rhs;
    rhs.deserialize(POPULATED_JSON_OBJECT);

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_FALSE(actual);
}
