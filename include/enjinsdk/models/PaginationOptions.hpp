#ifndef ENJINCPPSDK_PAGINATIONOPTIONS_HPP
#define ENJINCPPSDK_PAGINATIONOPTIONS_HPP

#include "enjinsdk/serialization/ISerializable.hpp"
#include <optional>

namespace enjin::sdk::models {

/// \brief Models a pagination input for pagination requests.
class PaginationOptions : public enjin::sdk::serialization::ISerializable {
public:
    /// \brief Default constructor.
    PaginationOptions() = default;

    std::string serialize() override;

    /// \brief Sets the page number to start at for the pagination.
    /// \param page The page number.
    /// \return This input for chaining.
    PaginationOptions& set_page(int page);

    /// \brief Sets the number of items per page for the pagination.
    /// \param limit The number of items per page.
    /// \return This input for chaining.
    PaginationOptions& set_limit(int limit);

    bool operator==(const PaginationOptions& rhs) const;

    bool operator!=(const PaginationOptions& rhs) const;

private:
    std::optional<int> page;
    std::optional<int> limit;

    constexpr static char PAGE_KEY[] = "page";
    constexpr static char LIMIT_KEY[] = "limit";
};

}

#endif //ENJINCPPSDK_PAGINATIONOPTIONS_HPP