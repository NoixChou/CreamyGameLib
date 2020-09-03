#ifdef CREAMY_USE_SDL

#include "DrawResource.hpp"

#include "Resource/TextureResource.hpp"

#include "../../../CreamyGameLib/include/Util/Color.hpp"
#include "../../../CreamyGameLib/include/Math/Vector2.hpp"

#include "SDL.h"

namespace creamyLib::impl
{
    void DrawTexture2D(const LibHandlePointer& libHandle, const resource::TextureResource& texture, const math::Vector2& position, const math::Vector2& scale)
    {
        const auto [x, y] = position.ToInteger();
        const auto [scaleX, scaleY] = scale;

        SDL_Rect l_Rect{ x, y, static_cast<int>(texture.width * scaleX), static_cast<int>(texture.height * scaleY) };

        SDL_RenderCopy(libHandle->sdlRenderer, texture.handle->texture, nullptr, &l_Rect);
    }
}

#endif
