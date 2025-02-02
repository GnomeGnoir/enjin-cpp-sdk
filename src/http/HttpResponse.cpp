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

#include "enjinsdk/HttpResponse.hpp"

#include "rapidjson/document.h"
#include <utility>

namespace enjin::sdk::http {

HttpResponse HttpResponseBuilder::build() {
    return HttpResponse(m_code, m_body, m_content_type);
}

HttpResponseBuilder& HttpResponseBuilder::code(uint16_t code) {
    m_code = std::optional<uint16_t>(code);
    return *this;
}

HttpResponseBuilder& HttpResponseBuilder::body(const std::string& body) {
    m_body = std::optional<std::string>(body);
    return *this;
}

HttpResponseBuilder& HttpResponseBuilder::content_type(const std::string& content_type) {
    m_content_type = std::optional<std::string>(content_type);
    return *this;
}

HttpResponse::HttpResponse(std::optional<uint16_t> code,
                           std::optional<std::string> body,
                           std::optional<std::string> content_type) :
        code(code),
        body(std::move(body)),
        content_type(std::move(content_type)) {
}

bool HttpResponse::is_success() const {
    return code.has_value() && code.value() >= 200 && code.value() < 300;
}

bool HttpResponse::is_empty() const {
    if (!body.has_value()) {
        return true;
    }

    rapidjson::Document document;
    document.Parse(body.value().c_str());

    return body.value().empty() || (document.IsObject() && document.ObjectEmpty());
}

const std::optional<unsigned short>& HttpResponse::get_code() const {
    return code;
}

const std::optional<std::string>& HttpResponse::get_body() const {
    return body;
}

const std::optional<std::string>& HttpResponse::get_content_type() const {
    return content_type;
}

bool HttpResponse::operator==(const HttpResponse& rhs) const {
    return code == rhs.code &&
           body == rhs.body &&
           content_type == rhs.content_type;
}

bool HttpResponse::operator!=(const HttpResponse& rhs) const {
    return !(rhs == *this);
}

}
