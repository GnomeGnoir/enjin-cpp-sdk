#ifndef ENJINCPPSDK_HTTPCLIENTIMPL_HPP
#define ENJINCPPSDK_HTTPCLIENTIMPL_HPP

#include "cpprest/http_client.h"
#include "enjinsdk/AbstractHttpClient.hpp"

namespace enjin::sdk::http {

/// \brief Implementation class for an HTTP client base on Microsoft's C++ Rest SDK.
class HttpClientImpl : public AbstractHttpClient {
public:
    /// \brief Creates the HTTP client and assigns a base URI.
    /// \param base_uri The base URI for the client.
    explicit HttpClientImpl(const std::string& base_uri);

    void close() override;

    std::future<HttpResponse> send_request(const HttpRequest& request) override;

private:
    web::http::client::http_client http_client;
};

}

#endif //ENJINCPPSDK_HTTPCLIENTIMPL_HPP