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

#ifndef ENJINCPPSDK_TRANSACTIONSORT_HPP
#define ENJINCPPSDK_TRANSACTIONSORT_HPP

#include "enjinsdk_export.h"
#include "enjinsdk/ISerializable.hpp"
#include "enjinsdk/models/SortDirection.hpp"
#include "enjinsdk/models/TransactionField.hpp"
#include <optional>

namespace enjin::sdk::models {

/// \brief Models sorting input for Transactions (Requests).
class ENJINSDK_EXPORT TransactionSort : public serialization::ISerializable {
public:
    /// \brief Default constructor.
    TransactionSort() = default;

    ~TransactionSort() override = default;

    [[nodiscard]] std::string serialize() const override;

    /// \brief Sets the field to sort by.
    /// \param field The field.
    /// \return This input for chaining.
    TransactionSort& set_field(TransactionField field);

    /// \brief Sets the direction to sort by.
    /// \param direction The direction.
    /// \return This input for chaining.
    TransactionSort& set_direction(SortDirection direction);

    bool operator==(const TransactionSort& rhs) const;

    bool operator!=(const TransactionSort& rhs) const;

private:
    std::optional<TransactionField> field;
    std::optional<SortDirection> direction;

    constexpr static char FIELD_KEY[] = "field";
    constexpr static char DIRECTION_KEY[] = "direction";
};

}

#endif //ENJINCPPSDK_TRANSACTIONSORT_HPP
