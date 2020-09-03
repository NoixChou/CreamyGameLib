#ifdef CREAMY_USE_SDL

#include "Resource/ResourceLoader.hpp"

#include "SDL.h"
#include "SDL_image.h"

namespace creamyLib::impl::resource
{
    std::optional<TextureResource> LoadTextureFromFile(const LibHandlePointer& libHandle, const std::string& fileName)
    {
        SDL_Surface* surface = IMG_Load(fileName.c_str());
        if(!surface)
        {
            SDL_Log("Failed to load texture file %s", fileName.c_str());
            return std::nullopt;
        }

        SDL_Texture* texture = SDL_CreateTextureFromSurface(libHandle->sdlRenderer, surface);
        SDL_FreeSurface(surface);
        if(!texture)
        {
            SDL_Log("Failed to convert surface to texture for %s", fileName.c_str());
            return std::nullopt;
        }

        int width;
        int height;
        SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);

        return std::make_optional(TextureResource(new TextureRawHandle{ texture }, width, height));
    }
}

#endif
