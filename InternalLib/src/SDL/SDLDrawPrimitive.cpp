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
        const auto [x, y] = position.ToInteger();
        const auto [width, height] = size.ToInteger();

        SDL_SetRenderDrawColor(libHandle->sdlRenderer, r, g, b, a);
        SDL_Rect l_Rect{ x, y, width, height };

        if (isFill)
        {
            SDL_RenderFillRect(libHandle->sdlRenderer, &l_Rect);
        }
        else
        {
            SDL_RenderDrawRect(libHandle->sdlRenderer, &l_Rect);
        }
    }
}

#endif
