#ifdef CREAMY_USE_DXLIB

#include "Resource/TextureResource.hpp"

#include <DxLib.h>

namespace creamyLib::impl::resource
{
    TextureResource::~TextureResource() = default;

    void TextureResource::destroy()
    {
        if (handle->texture < 0) return;

        DxLib::DeleteGraph(handle->texture);
        handle->texture = -1;

        delete handle;
        handle = nullptr;
    }
}

#endif
