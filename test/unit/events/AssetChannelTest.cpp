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
#include "AssetChannel.hpp"
#include "ChannelsTestSuite.hpp"
#include <string>

using namespace enjin::sdk::events;
using namespace enjin::test::suites;

class AssetChannelTest : public ChannelsTestSuite,
                         public testing::Test {
};

TEST_F(AssetChannelTest, ChannelReturnsExpectedString) {
    // Arrange
    const std::string expected("enjincloud.kovan.asset.1");
    AssetChannel channel(create_default_platform(), "1");

    // Act
    std::string actual = channel.channel();

    // Assert
    ASSERT_EQ(expected, actual);
}
