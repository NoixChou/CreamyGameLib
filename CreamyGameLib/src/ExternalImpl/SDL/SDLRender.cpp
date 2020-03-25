#include "ExternalImpl/SDL/SDLRender.hpp"

#include <SDL.h>

namespace creamyLib::impl
{
    void RenderService::ClearBuffer(const LibHandlePointer sdlHandle)
    {
        SDL_RenderClear(sdlHandle->sdlRenderer);
    }

    void RenderService::PresentBuffer(const LibHandlePointer sdlHandle)
    {
        SDL_RenderPresent(sdlHandle->sdlRenderer);
    }
}
