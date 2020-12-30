#pragma once

#include <utility>

#include "ResourceInterface.hpp"

#ifdef CREAMY_USE_SDL
struct SDL_Texture;
#endif

namespace creamyLib::impl::resource
{
    struct TextureRawHandle
    {
#ifdef CREAMY_USE_DXLIB
        int texture;
#endif
#ifdef CREAMY_USE_SDL
        SDL_Texture* texture;
#endif
    };

    struct TextureResource : ResourceInterface
    {
        TextureRawHandle* handle;
        int width;
        int height;

        TextureResource(TextureRawHandle* const handle, int width, int height) : handle(handle), width(width), height(height) {}
        ~TextureResource();

        void destroy() override;
    };
}
