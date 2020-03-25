#ifdef CREAMY_USE_SDL

#include "Render.hpp"

#include "SDL.h"

namespace creamyLib::impl
{
    void RenderService::ClearBuffer(const LibHandlePointer libHandle)
    {
        SDL_RenderClear(libHandle->sdlRenderer);
    }

    void RenderService::PresentBuffer(const LibHandlePointer libHandle)
    {
        SDL_RenderPresent(libHandle->sdlRenderer);
    }
}

#endif
