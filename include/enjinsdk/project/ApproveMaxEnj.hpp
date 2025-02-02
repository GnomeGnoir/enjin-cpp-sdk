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

#ifndef ENJINCPPSDK_PROJECTAPPROVEMAXENJ_HPP
#define ENJINCPPSDK_PROJECTAPPROVEMAXENJ_HPP

#include "enjinsdk_export.h"
#include "enjinsdk/internal/AbstractGraphqlRequest.hpp"
#include "enjinsdk/project/ProjectTransactionRequestArguments.hpp"

namespace enjin::sdk::project {

/// \brief Request for approving the crypto items contract to spend the maximum amount of ENJ.
class ENJINSDK_EXPORT ApproveMaxEnj : public graphql::AbstractGraphqlRequest,
                                      public ProjectTransactionRequestArguments<ApproveMaxEnj> {
public:
    /// \brief Default constructor.
    ApproveMaxEnj();

    ~ApproveMaxEnj() override = default;

    [[nodiscard]] std::string serialize() const override;

    bool operator==(const ApproveMaxEnj& rhs) const;

    bool operator!=(const ApproveMaxEnj& rhs) const;
};

template ENJINSDK_EXPORT ApproveMaxEnj&
ProjectTransactionRequestArguments<ApproveMaxEnj>::set_eth_address(const std::string& address);

}

namespace enjin::sdk::shared {

template ENJINSDK_EXPORT project::ApproveMaxEnj&
TransactionFragmentArguments<project::ApproveMaxEnj>::set_asset_id_format(models::AssetIdFormat asset_id_format);

template ENJINSDK_EXPORT project::ApproveMaxEnj&
TransactionFragmentArguments<project::ApproveMaxEnj>::set_with_blockchain_data();

template ENJINSDK_EXPORT project::ApproveMaxEnj&
TransactionFragmentArguments<project::ApproveMaxEnj>::set_with_meta();

template ENJINSDK_EXPORT project::ApproveMaxEnj&
TransactionFragmentArguments<project::ApproveMaxEnj>::set_with_encoded_data();

template ENJINSDK_EXPORT project::ApproveMaxEnj&
TransactionFragmentArguments<project::ApproveMaxEnj>::set_with_asset_data();

template ENJINSDK_EXPORT project::ApproveMaxEnj&
TransactionFragmentArguments<project::ApproveMaxEnj>::set_with_signed_txs();

template ENJINSDK_EXPORT project::ApproveMaxEnj&
TransactionFragmentArguments<project::ApproveMaxEnj>::set_with_error();

template ENJINSDK_EXPORT project::ApproveMaxEnj&
TransactionFragmentArguments<project::ApproveMaxEnj>::set_with_nonce();

template ENJINSDK_EXPORT project::ApproveMaxEnj&
TransactionFragmentArguments<project::ApproveMaxEnj>::set_with_state();

template ENJINSDK_EXPORT project::ApproveMaxEnj&
TransactionFragmentArguments<project::ApproveMaxEnj>::set_with_receipt();

template ENJINSDK_EXPORT project::ApproveMaxEnj&
TransactionFragmentArguments<project::ApproveMaxEnj>::set_with_receipt_logs();

template ENJINSDK_EXPORT project::ApproveMaxEnj&
TransactionFragmentArguments<project::ApproveMaxEnj>::set_with_log_event();

template ENJINSDK_EXPORT project::ApproveMaxEnj&
TransactionFragmentArguments<project::ApproveMaxEnj>::set_with_transaction_project_uuid();

}

#endif //ENJINCPPSDK_PROJECTAPPROVEMAXENJ_HPP
