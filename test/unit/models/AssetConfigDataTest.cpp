#include "JsonTestSuite.hpp"
#include "enjinsdk/models/AssetConfigData.hpp"

using namespace enjin::sdk::models;

class AssetConfigDataTest : public JsonTestSuite {
public:
    AssetConfigData class_under_test;

    constexpr static char POPULATED_JSON_OBJECT[] =
            R"({"meltFeeRatio":1,"meltFeeMaxRatio":1,"meltValue":"1","metadataURI":"1","transferable":"PERMANENT","transferFeeSettings":{}})";
};

TEST_F(AssetConfigDataTest, DeserializeEmptyStringFieldsDoNotHaveValues) {
    // Arrange
    const std::string json;

    // Act
    class_under_test.deserialize(json);

    // Assert
    EXPECT_FALSE(class_under_test.get_melt_fee_ratio().has_value());
    EXPECT_FALSE(class_under_test.get_melt_fee_max_ratio().has_value());
    EXPECT_FALSE(class_under_test.get_melt_value().has_value());
    EXPECT_FALSE(class_under_test.get_metadata_uri().has_value());
    EXPECT_FALSE(class_under_test.get_transferable().has_value());
    EXPECT_FALSE(class_under_test.get_transfer_fee_settings().has_value());
}

TEST_F(AssetConfigDataTest, DeserializeEmptyJsonObjectFieldsDoNotHaveValues) {
    // Arrange
    const std::string json(EMPTY_JSON_OBJECT);

    // Act
    class_under_test.deserialize(json);

    // Assert
    EXPECT_FALSE(class_under_test.get_melt_fee_ratio().has_value());
    EXPECT_FALSE(class_under_test.get_melt_fee_max_ratio().has_value());
    EXPECT_FALSE(class_under_test.get_melt_value().has_value());
    EXPECT_FALSE(class_under_test.get_metadata_uri().has_value());
    EXPECT_FALSE(class_under_test.get_transferable().has_value());
    EXPECT_FALSE(class_under_test.get_transfer_fee_settings().has_value());
}

TEST_F(AssetConfigDataTest, DeserializePopulatedJsonObjectFieldsHaveExpectedValues) {
    // Arrange
    const int expected_int = 1;
    const std::string expected_string("1");
    const AssetTransferable expected_transferable = AssetTransferable::PERMANENT;
    const AssetTransferFeeSettings expected_transfer_fee_settings;
    const std::string json(POPULATED_JSON_OBJECT);

    // Act
    class_under_test.deserialize(json);

    // Assert
    EXPECT_EQ(expected_int, class_under_test.get_melt_fee_ratio().value());
    EXPECT_EQ(expected_int, class_under_test.get_melt_fee_max_ratio().value());
    EXPECT_EQ(expected_string, class_under_test.get_melt_value().value());
    EXPECT_EQ(expected_string, class_under_test.get_metadata_uri().value());
    EXPECT_EQ(expected_transferable, class_under_test.get_transferable().value());
    EXPECT_EQ(expected_transfer_fee_settings, class_under_test.get_transfer_fee_settings().value());
}

TEST_F(AssetConfigDataTest, EqualityNeitherSideIsPopulatedReturnsTrue) {
    // Arrange
    AssetConfigData lhs;
    AssetConfigData rhs;

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(AssetConfigDataTest, EqualityBothSidesArePopulatedReturnsTrue) {
    // Arrange
    AssetConfigData lhs;
    AssetConfigData rhs;
    lhs.deserialize(POPULATED_JSON_OBJECT);
    rhs.deserialize(POPULATED_JSON_OBJECT);

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(AssetConfigDataTest, EqualityLeftSideIsPopulatedReturnsFalse) {
    // Arrange
    AssetConfigData lhs;
    AssetConfigData rhs;
    lhs.deserialize(POPULATED_JSON_OBJECT);

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(AssetConfigDataTest, EqualityRightSideIsPopulatedReturnsFalse) {
    // Arrange
    AssetConfigData lhs;
    AssetConfigData rhs;
    rhs.deserialize(POPULATED_JSON_OBJECT);

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_FALSE(actual);
}