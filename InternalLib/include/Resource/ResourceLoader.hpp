#pragma once

#include <string>
#include <optional>

#include "../../InternalLib/include/Handle.hpp"

#include "TextureResource.hpp"

namespace creamyLib::impl::resource
{
    class ResourceLoader
    {
    private:
        LibHandlePointer libHandle_ = nullptr;

    public:
        ResourceLoader(const LibHandlePointer& libHandle);

        [[nodiscard]] std::optional<TextureResource> loadTextureFromFile(const std::string& fileName) const;
    };
}
