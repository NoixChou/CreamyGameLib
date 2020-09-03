#include "Engine/Resource/Resource.hpp"

#include "Resource/ResourceInterface.hpp"

#include <utility>

namespace creamyLib::engine::resource
{
    Resource::Resource(std::any resource): resource(std::move(resource)) {}

    Resource::~Resource()
    {
    }

    std::any& Resource::GetResource()
    {
        return resource;
    }
}
