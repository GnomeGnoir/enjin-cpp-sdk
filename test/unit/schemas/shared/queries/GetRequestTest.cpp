#include "JsonTestSuite.hpp"
#include "TransactionFragmentArgumentsTestSuite.hpp"
#include "enjinsdk/shared/GetRequest.hpp"
#include "gtest/gtest.h"
#include <string>

using namespace enjin::sdk::shared;
using namespace enjin::test::suites;

class GetRequestTest : public TransactionFragmentArgumentsTestSuite<GetRequest>,
                       public JsonTestSuite,
                       public testing::Test {
public:
    GetRequest class_under_test;

    constexpr static char POPULATED_JSON_OBJECT[] =
            R"({"id":1,"transactionId":"1"})";

    static GetRequest create_default_request() {
        GetRequest request = GetRequest()
                .set_id(1)
                .set_transaction_id("1");
        set_transaction_fragment_arguments(request);
        return request;
    }
};

TEST_F(GetRequestTest, SerializeNoSetFieldsReturnsEmptyJsonObject) {
    // Arrange
    const std::string expected(EMPTY_JSON_OBJECT);

    // Act
    std::string actual = class_under_test.serialize();

    // Assert
    ASSERT_EQ(expected, actual);
}

TEST_F(GetRequestTest, SerializeSetFieldsReturnsExpectedJsonObject) {
    // Arrange
    const std::string expected(POPULATED_JSON_OBJECT);
    class_under_test.set_id(1)
                    .set_transaction_id("1");

    // Act
    std::string actual = class_under_test.serialize();

    // Assert
    ASSERT_EQ(expected, actual);
}

TEST_F(GetRequestTest, EqualityNeitherSideIsPopulatedReturnsTrue) {
    // Arrange
    GetRequest lhs;
    GetRequest rhs;

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(GetRequestTest, EqualityBothSidesArePopulatedReturnsTrue) {
    // Arrange
    GetRequest lhs = create_default_request();
    GetRequest rhs = create_default_request();

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(GetRequestTest, EqualityLeftSideIsPopulatedReturnsFalse) {
    // Arrange
    GetRequest lhs = create_default_request();
    GetRequest rhs;

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(GetRequestTest, EqualityRightSideIsPopulatedReturnsFalse) {
    // Arrange
    GetRequest lhs;
    GetRequest rhs = create_default_request();

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_FALSE(actual);
}
