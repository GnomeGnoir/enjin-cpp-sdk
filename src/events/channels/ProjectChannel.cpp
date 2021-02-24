#include "ProjectChannel.hpp"

#include "StringUtils.hpp"
#include <sstream>

namespace enjin::sdk::events {

ProjectChannel::ProjectChannel(const models::Platform& platform, int project_id)
        : platform(platform), project_id(project_id) {
}

std::string ProjectChannel::channel() const {
    return (std::stringstream() << "enjincloud."
                                << utils::to_lower(platform.get_network().value())
                                << ".project."
                                << project_id
    ).str();
}

}