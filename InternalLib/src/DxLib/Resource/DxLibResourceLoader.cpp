#ifdef CREAMY_USE_DXLIB

#include "Resource/ResourceLoader.hpp"

#include "DxLib.h"

namespace creamyLib::impl::resource
{
    ResourceLoader::ResourceLoader(const LibHandlePointer& libHandle) : libHandle_(libHandle) {}

    std::optional<TextureResource> ResourceLoader::loadTextureFromFile(const std::string& fileName) const
    {
        int texture = DxLib::LoadGraph(fileName.c_str());
        if(texture < 0)
        {
            DxLib::LogFileFmtAdd("Failed to load texture file %s", fileName.c_str());
            return std::nullopt;
        }

        int width;
        int height;
        DxLib::GetGraphSize(texture, &width, &height);

        return std::make_optional(TextureResource(new TextureRawHandle{ texture }, width, height));
    }
}

#endif
