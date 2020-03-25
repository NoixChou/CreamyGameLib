#ifdef CREAMY_USE_SDL

#include "Render.hpp"

#include "../../../CreamyGameLib/include/Util/Color.hpp"

#include "SDL.h"

namespace creamyLib::impl
{
    void RenderService::ClearBuffer(const LibHandlePointer& libHandle, const Color& color)
    {
        const auto [r, g, b, a] = color;
        SDL_SetRenderDrawColor(libHandle->sdlRenderer, r, g, b, a);
        SDL_RenderClear(libHandle->sdlRenderer);
    }

    void RenderService::PresentBuffer(const LibHandlePointer& libHandle)
    {
        SDL_RenderPresent(libHandle->sdlRenderer);
    }
}

#endif
