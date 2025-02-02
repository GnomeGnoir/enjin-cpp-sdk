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

#ifndef ENJINCPPSDK_PROJECTMELTASSET_HPP
#define ENJINCPPSDK_PROJECTMELTASSET_HPP

#include "enjinsdk_export.h"
#include "enjinsdk/internal/AbstractGraphqlRequest.hpp"
#include "enjinsdk/models/Melt.hpp"
#include "enjinsdk/project/ProjectTransactionRequestArguments.hpp"
#include <optional>
#include <vector>

namespace enjin::sdk::project {

/// \brief Request for melting a asset.
class ENJINSDK_EXPORT MeltAsset : public graphql::AbstractGraphqlRequest,
                                  public ProjectTransactionRequestArguments<MeltAsset> {
public:
    /// \brief Default constructor.
    MeltAsset();

    ~MeltAsset() override = default;

    [[nodiscard]] std::string serialize() const override;

    /// Sets the melts to be performed.
    /// \param melts The melts.
    /// \return This request for chaining.
    MeltAsset& set_melts(std::vector<models::Melt> melts);

    bool operator==(const MeltAsset& rhs) const;

    bool operator!=(const MeltAsset& rhs) const;

private:
    std::optional<std::vector<models::Melt>> melts;
};

template ENJINSDK_EXPORT MeltAsset&
ProjectTransactionRequestArguments<MeltAsset>::set_eth_address(const std::string& address);

}

namespace enjin::sdk::shared {

template ENJINSDK_EXPORT project::MeltAsset&
TransactionFragmentArguments<project::MeltAsset>::set_asset_id_format(models::AssetIdFormat asset_id_format);

template ENJINSDK_EXPORT project::MeltAsset&
TransactionFragmentArguments<project::MeltAsset>::set_with_blockchain_data();

template ENJINSDK_EXPORT project::MeltAsset&
TransactionFragmentArguments<project::MeltAsset>::set_with_meta();

template ENJINSDK_EXPORT project::MeltAsset&
TransactionFragmentArguments<project::MeltAsset>::set_with_encoded_data();

template ENJINSDK_EXPORT project::MeltAsset&
TransactionFragmentArguments<project::MeltAsset>::set_with_asset_data();

template ENJINSDK_EXPORT project::MeltAsset&
TransactionFragmentArguments<project::MeltAsset>::set_with_signed_txs();

template ENJINSDK_EXPORT project::MeltAsset&
TransactionFragmentArguments<project::MeltAsset>::set_with_error();

template ENJINSDK_EXPORT project::MeltAsset&
TransactionFragmentArguments<project::MeltAsset>::set_with_nonce();

template ENJINSDK_EXPORT project::MeltAsset&
TransactionFragmentArguments<project::MeltAsset>::set_with_state();

template ENJINSDK_EXPORT project::MeltAsset&
TransactionFragmentArguments<project::MeltAsset>::set_with_receipt();

template ENJINSDK_EXPORT project::MeltAsset&
TransactionFragmentArguments<project::MeltAsset>::set_with_receipt_logs();

template ENJINSDK_EXPORT project::MeltAsset&
TransactionFragmentArguments<project::MeltAsset>::set_with_log_event();

template ENJINSDK_EXPORT project::MeltAsset&
TransactionFragmentArguments<project::MeltAsset>::set_with_transaction_project_uuid();

}

#endif //ENJINCPPSDK_PROJECTMELTASSET_HPP
