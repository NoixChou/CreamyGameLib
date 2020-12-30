#include "Engine/Resource/Resource.hpp"

#include "Resource/ResourceInterface.hpp"

#include <utility>

namespace creamyLib::engine::resource
{
    Resource::Resource(std::any resource): resource_(std::move(resource)) {}

    Resource::~Resource()
    {
    }

    std::any& Resource::getResource()
    {
        return resource_;
    }
}
