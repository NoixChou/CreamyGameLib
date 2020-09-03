#pragma once

#include <optional>
#include <string>

#include "Handle.hpp"
#include "TextureResource.hpp"

namespace creamyLib::impl::resource
{
    std::optional<TextureResource> LoadTextureFromFile(const LibHandlePointer& libHandle, const std::string& fileName);
}
