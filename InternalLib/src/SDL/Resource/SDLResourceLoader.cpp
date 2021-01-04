#ifdef CREAMY_USE_SDL

#include "Resource/ResourceLoader.hpp"

#include "SDL.h"
#include "SDL_image.h"

namespace creamyLib::impl::resource
{
    ResourceLoader::ResourceLoader(const LibHandlePointer& libHandle): libHandle_(libHandle) {}

    std::optional<TextureResource> ResourceLoader::loadTextureFromFile(const std::string& fileName) const
    {
        SDL_Surface* surface = IMG_Load(fileName.c_str());
        if(!surface)
        {
            SDL_Log("Failed to load texture file %s", fileName.c_str());
            return std::nullopt;
        }

        SDL_Texture* texture = SDL_CreateTextureFromSurface(libHandle_->sdlRenderer, surface);
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
