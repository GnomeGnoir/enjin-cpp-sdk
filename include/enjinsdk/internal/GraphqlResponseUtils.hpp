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

#ifndef ENJINCPPSDK_GRAPHQLRESPONSEUTILS_HPP
#define ENJINCPPSDK_GRAPHQLRESPONSEUTILS_HPP

#include "enjinsdk_export.h"
#include "enjinsdk/models/PaginationCursor.hpp"
#include <optional>
#include <string>
#include <utility>
#include <vector>

namespace enjin::sdk::graphql {

/// \brief Extracts the boolean result from the data JSON.
/// \param data_json The JSON.
/// \return Optional with the boolean result.
ENJINSDK_EXPORT
std::optional<bool> get_bool_result(const std::string& data_json);

/// \brief Extracts the pagination cursor and serialized items array from the data JSON.
/// \param data_json The JSON.
/// \return Optional with the pagination cursor and serialized items array.
ENJINSDK_EXPORT
std::optional<std::pair<models::PaginationCursor, std::vector<std::string>>>
get_pagination_data(const std::string& data_json);

/// \brief Extracts the serialized result objects array from the data JSON.
/// \param data_json The JSON.
/// \return Optional with the serialized result objects.
ENJINSDK_EXPORT
std::optional<std::vector<std::string>> get_serialized_object_array(const std::string& data_json);

/// \brief Extracts the serialized result object from the data JSON.
/// \param data_json The JSON.
/// \return Optional with the serialized result object.
ENJINSDK_EXPORT
std::optional<std::string> get_serialized_result_object(const std::string& data_json);

/// \brief Determines if the given JSON has pagination data from the platform.
/// \param data_json The JSON.
/// \return Whether the data JSON has pagination data.
ENJINSDK_EXPORT
bool is_json_paginated(const std::string& data_json);

}

#endif //ENJINCPPSDK_GRAPHQLRESPONSEUTILS_HPP
