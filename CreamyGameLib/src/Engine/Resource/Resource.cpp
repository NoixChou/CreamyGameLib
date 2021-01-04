#include "Engine/Resource/Resource.hpp"

#include <utility>

namespace creamyLib::engine::resource
{
    Resource::Resource(std::any resource): resource_(std::move(resource))
    {

    }

    std::any& Resource::getRawResource()
    {
        return resource_;
    }
}
