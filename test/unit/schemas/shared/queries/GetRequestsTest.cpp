#include "JsonTestSuite.hpp"
#include "PaginationArgumentsTestSuite.hpp"
#include "TransactionFragmentArgumentsTestSuite.hpp"
#include "enjinsdk/shared/GetRequests.hpp"
#include "gtest/gtest.h"
#include <string>

using namespace enjin::sdk::models;
using namespace enjin::sdk::shared;
using namespace enjin::test::suites;

class GetRequestsTest : public TransactionFragmentArgumentsTestSuite<GetRequests>,
                        public PaginationArgumentsTestSuite<GetRequests>,
                        public JsonTestSuite,
                        public testing::Test {
public:
    GetRequests class_under_test;

    constexpr static char POPULATED_JSON_OBJECT[] =
            R"({"filter":{},"sort":{}})";

    static GetRequests create_default_request() {
        GetRequests requests = GetRequests()
                .set_filter(TransactionFilter())
                .set_sort(TransactionSort());
        set_transaction_fragment_arguments(requests);
        set_pagination_arguments(requests);
        return requests;
    }
};

TEST_F(GetRequestsTest, SerializeNoSetFieldsReturnsEmptyJsonObject) {
    // Arrange
    const std::string expected(EMPTY_JSON_OBJECT);

    // Act
    std::string actual = class_under_test.serialize();

    // Assert
    ASSERT_EQ(expected, actual);
}

TEST_F(GetRequestsTest, SerializeSetFieldsReturnsExpectedJsonObject) {
    // Arrange
    const std::string expected(POPULATED_JSON_OBJECT);
    class_under_test.set_filter(TransactionFilter())
                    .set_sort(TransactionSort());

    // Act
    std::string actual = class_under_test.serialize();

    // Assert
    ASSERT_EQ(expected, actual);
}

TEST_F(GetRequestsTest, EqualityNeitherSideIsPopulatedReturnsTrue) {
    // Arrange
    GetRequests lhs;
    GetRequests rhs;

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(GetRequestsTest, EqualityBothSidesArePopulatedReturnsTrue) {
    // Arrange
    GetRequests lhs = create_default_request();
    GetRequests rhs = create_default_request();

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(GetRequestsTest, EqualityLeftSideIsPopulatedReturnsFalse) {
    // Arrange
    GetRequests lhs = create_default_request();
    GetRequests rhs;

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(GetRequestsTest, EqualityRightSideIsPopulatedReturnsFalse) {
    // Arrange
    GetRequests lhs;
    GetRequests rhs = create_default_request();

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_FALSE(actual);
}
