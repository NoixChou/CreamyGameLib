#ifdef CREAMY_USE_SDL

#include "DrawPrimitive.hpp"

#include "../../../CreamyGameLib/include/Util/Color.hpp"
#include "../../../CreamyGameLib/include/Math/Vector2.hpp"

#include "SDL.h"

namespace creamyLib::impl
{
    void DrawRect(const LibHandlePointer& libHandle, const math::Vector2& position, const math::Vector2& size, const Color& color, bool isFill)
    {
        const auto [r, g, b, a] = color;
        const auto [x, y] = position.toInteger();
        const auto [width, height] = size.toInteger();

        SDL_SetRenderDrawColor(libHandle->sdlRenderer, r, g, b, a);
        SDL_Rect rect{ x, y, width, height };

        if (isFill)
        {
            SDL_RenderFillRect(libHandle->sdlRenderer, &rect);
        }
        else
        {
            SDL_RenderDrawRect(libHandle->sdlRenderer, &rect);
        }
    }
}

#endif
