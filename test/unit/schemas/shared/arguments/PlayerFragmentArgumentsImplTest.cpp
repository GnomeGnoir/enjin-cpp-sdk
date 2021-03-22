#include "gtest/gtest.h"
#include "JsonTestSuite.hpp"
#include "enjinsdk/internal/PlayerFragmentArgumentsImpl.hpp"
#include <string>

using namespace enjin::sdk::shared;
using namespace enjin::test::suites;

class PlayerFragmentArgumentsImplTest : public JsonTestSuite,
                                        public testing::Test {
public:
    PlayerFragmentArgumentsImpl class_under_test;

    constexpr static char POPULATED_JSON_OBJECT[] =
            R"({"withLinkingInfo":true,"linkingCodeQrSize":1,"withPlayerWallet":true})";

    static PlayerFragmentArgumentsImpl create_default_arguments() {
        PlayerFragmentArgumentsImpl arguments;
        arguments.set_with_linking_info();
        arguments.set_qr_size(1);
        arguments.set_with_wallet();
        return arguments;
    }
};

TEST_F(PlayerFragmentArgumentsImplTest, SerializeNoSetFieldsReturnsEmptyJsonObject) {
    // Arrange
    const std::string expected(EMPTY_JSON_OBJECT);

    // Act
    std::string actual = class_under_test.serialize();

    // Assert
    ASSERT_EQ(expected, actual);
}

TEST_F(PlayerFragmentArgumentsImplTest, SerializeSetFieldsReturnsExpectedJsonObject) {
    // Arrange
    const std::string expected(POPULATED_JSON_OBJECT);
    class_under_test.set_with_linking_info();
    class_under_test.set_qr_size(1);
    class_under_test.set_with_wallet();

    // Act
    std::string actual = class_under_test.serialize();

    // Assert
    ASSERT_EQ(expected, actual);
}

TEST_F(PlayerFragmentArgumentsImplTest, EqualityNeitherSideIsPopulatedReturnsTrue) {
    // Arrange
    PlayerFragmentArgumentsImpl lhs;
    PlayerFragmentArgumentsImpl rhs;

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(PlayerFragmentArgumentsImplTest, EqualityBothSidesArePopulatedReturnsTrue) {
    // Arrange
    PlayerFragmentArgumentsImpl lhs = create_default_arguments();
    PlayerFragmentArgumentsImpl rhs = create_default_arguments();

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(PlayerFragmentArgumentsImplTest, EqualityLeftSideIsPopulatedReturnsFalse) {
    // Arrange
    PlayerFragmentArgumentsImpl lhs = create_default_arguments();
    PlayerFragmentArgumentsImpl rhs;

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(PlayerFragmentArgumentsImplTest, EqualityRightSideIsPopulatedReturnsFalse) {
    // Arrange
    PlayerFragmentArgumentsImpl lhs;
    PlayerFragmentArgumentsImpl rhs = create_default_arguments();

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_FALSE(actual);
}