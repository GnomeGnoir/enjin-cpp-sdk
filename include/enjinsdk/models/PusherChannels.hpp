#ifndef ENJINCPPSDK_PUSHERCHANNELS_HPP
#define ENJINCPPSDK_PUSHERCHANNELS_HPP

#include "enjinsdk/serialization/IDeserializable.hpp"
#include <optional>
#include <string>

namespace enjin::sdk::models {

/// \brief Models Pusher channels used by the platform.
class PusherChannels : public enjin::sdk::serialization::IDeserializable {
public:
    /// \brief Default constructor.
    PusherChannels() = default;

    void deserialize(const std::string& json) override;

    /// \brief Returns the project channel.
    /// \return The project channel.
    [[nodiscard]] const std::optional<std::string>& get_project() const;

    /// \brief Returns the player channel.
    /// \return The player channel.
    [[nodiscard]] const std::optional<std::string>& get_player() const;

    /// \brief Returns the token channel.
    /// \return The token channel.
    [[nodiscard]] const std::optional<std::string>& get_token() const;

    /// \brief Returns the wallet channel.
    /// \return The wallet channel.
    [[nodiscard]] const std::optional<std::string>& get_wallet() const;

    bool operator==(const PusherChannels& rhs) const;

    bool operator!=(const PusherChannels& rhs) const;

private:
    std::optional<std::string> project;
    std::optional<std::string> player;
    std::optional<std::string> token;
    std::optional<std::string> wallet;

    constexpr static char PROJECT_KEY[] = "app";
    constexpr static char PLAYER_KEY[] = "player";
    constexpr static char TOKEN_KEY[] = "token";
    constexpr static char WALLET_KEY[] = "wallet";
};

}

#endif //ENJINCPPSDK_PUSHERCHANNELS_HPP