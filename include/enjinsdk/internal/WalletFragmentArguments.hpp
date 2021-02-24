#ifndef ENJINCPPSDK_SHAREDWALLETFRAGMENTARGUMENTS_HPP
#define ENJINCPPSDK_SHAREDWALLETFRAGMENTARGUMENTS_HPP

#include "enjinsdk_export.h"
#include "enjinsdk/serialization/ISerializable.hpp"
#include <optional>

namespace enjin::sdk::shared {

/// \brief Internal implementation class for storing values of a GraphQL Wallet fragment.
class ENJINSDK_EXPORT WalletFragmentArguments : public serialization::ISerializable {
public:
    /// \brief Default constructor.
    WalletFragmentArguments() = default;

    ~WalletFragmentArguments() override = default;

    std::string serialize() override;

    /// \brief Sets the value for the associated field to true.
    void set_with_assets_created();

    bool operator==(const WalletFragmentArguments& rhs) const;

    bool operator!=(const WalletFragmentArguments& rhs) const;

private:
    std::optional<bool> with_assets_created;
};

}

#endif //ENJINCPPSDK_SHAREDWALLETFRAGMENTARGUMENTS_HPP
