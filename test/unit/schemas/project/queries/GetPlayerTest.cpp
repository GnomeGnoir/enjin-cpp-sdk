#include "JsonTestSuite.hpp"
#include "PlayerFragmentArgumentsTestSuite.hpp"
#include "enjinsdk/project/GetPlayer.hpp"
#include "gtest/gtest.h"
#include <string>

using namespace enjin::sdk::project;
using namespace enjin::test::suites;

class GetPlayerTest : public PlayerFragmentArgumentsTestSuite<GetPlayer>,
                      public JsonTestSuite,
                      public testing::Test {
public:
    GetPlayer class_under_test;

    constexpr static char POPULATED_JSON_OBJECT[] =
            R"({"id":"1"})";

    static GetPlayer create_default_request() {
        GetPlayer request = GetPlayer()
                .set_id("1");
        set_player_fragment_arguments(request);
        return request;
    }
};

TEST_F(GetPlayerTest, SerializeNoSetFieldsReturnsEmptyJsonObject) {
    // Arrange
    const std::string expected(EMPTY_JSON_OBJECT);

    // Act
    std::string actual = class_under_test.serialize();

    // Assert
    ASSERT_EQ(expected, actual);
}

TEST_F(GetPlayerTest, SerializeSetFieldsReturnsExpectedJsonObject) {
    // Arrange
    const std::string expected(POPULATED_JSON_OBJECT);
    class_under_test.set_id("1");

    // Act
    std::string actual = class_under_test.serialize();

    // Assert
    ASSERT_EQ(expected, actual);
}

TEST_F(GetPlayerTest, EqualityNeitherSideIsPopulatedReturnsTrue) {
    // Arrange
    GetPlayer lhs;
    GetPlayer rhs;

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(GetPlayerTest, EqualityBothSidesArePopulatedReturnsTrue) {
    // Arrange
    GetPlayer lhs = create_default_request();
    GetPlayer rhs = create_default_request();

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(GetPlayerTest, EqualityLeftSideIsPopulatedReturnsFalse) {
    // Arrange
    GetPlayer lhs = create_default_request();
    GetPlayer rhs;

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(GetPlayerTest, EqualityRightSideIsPopulatedReturnsFalse) {
    // Arrange
    GetPlayer lhs;
    GetPlayer rhs = create_default_request();

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_FALSE(actual);
}
