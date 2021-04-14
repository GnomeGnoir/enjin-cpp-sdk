#ifndef ENJINCPPSDK_PLAYERCLIENT_HPP
#define ENJINCPPSDK_PLAYERCLIENT_HPP

#include "enjinsdk_export.h"
#include "enjinsdk/IHttpClient.hpp"
#include "enjinsdk/IClient.hpp"
#include "enjinsdk/TrustedPlatformMiddleware.hpp"
#include "enjinsdk/player/PlayerSchema.hpp"
#include <memory>
#include <optional>
#include <string>

namespace enjin::sdk {

class PlayerClient;

/// \brief Builder class for PlayerClient.
class ENJINSDK_EXPORT PlayerClientBuilder {
public:
    /// \brief Default constructor.
    PlayerClientBuilder() = default;

    /// \brief Default destructor.
    ~PlayerClientBuilder() = default;

    /// \brief Builds the client and provides the unique pointer for it.
    /// \return The client.
    [[nodiscard]] std::unique_ptr<PlayerClient> build();

    /// \brief Sets the base URI of the underlying HTTP client if one is not provided.
    /// \param base_uri The base URI.
    /// \return This builder for chaining.
    PlayerClientBuilder& base_uri(const std::string& base_uri);

    /// \brief Sets the underlying HTTP client implementation for the platform client to use.
    /// \param http_client The client implementation.
    /// \return This builder for chaining.
    PlayerClientBuilder& http_client(std::unique_ptr<http::IHttpClient> http_client);

    /// \brief Sets whether the client will have debugging enabled.
    /// \param debug The debug state.
    /// \return This builder for chaining.
    PlayerClientBuilder& debug(int debug);

    /// \brief Sets the logger to be used by the client.
    /// \param logger The logger.
    /// \return This builder for chaining.
    PlayerClientBuilder& logger(std::shared_ptr<utils::Logger> logger);

private:
    std::optional<std::string> m_base_uri;
    std::unique_ptr<http::IHttpClient> m_http_client;
    std::optional<bool> m_debug;
    std::shared_ptr<utils::Logger> m_logger;
};

/// \brief Client for using the player schema.
class ENJINSDK_EXPORT PlayerClient : public IClient,
                                     public player::PlayerSchema {
public:
    PlayerClient() = delete;

    ~PlayerClient() override;

    void auth(const std::string& token) override;

    void close() override;

    [[nodiscard]] bool is_authenticated() const override;

    [[nodiscard]] bool is_closed() const override;

private:
    explicit PlayerClient(TrustedPlatformMiddleware middleware, std::shared_ptr<utils::Logger> logger);

    friend std::unique_ptr<PlayerClient> PlayerClientBuilder::build();
};

}

#endif //ENJINCPPSDK_PLAYERCLIENT_HPP
