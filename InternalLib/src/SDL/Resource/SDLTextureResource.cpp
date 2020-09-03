#ifdef CREAMY_USE_SDL

#include "Resource/TextureResource.hpp"

#include <SDL.h>

namespace creamyLib::impl::resource
{
    TextureResource::~TextureResource() = default;

    void TextureResource::Destroy()
    {
        if (!handle->texture) return;
        SDL_DestroyTexture(handle->texture);
        handle->texture = nullptr;

        delete handle;
        handle = nullptr;
    }
}

#endif
