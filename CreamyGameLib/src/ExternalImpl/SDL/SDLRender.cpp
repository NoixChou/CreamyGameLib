#include "ExternalImpl/SDL/SDLRender.hpp"

#include <SDL.h>

namespace creamyLib::impl
{
    void ClearBuffer(const SDLHandlePointer sdlHandle)
    {
        SDL_RenderClear(sdlHandle->sdlRenderer);
    }

    void PresentBuffer(const SDLHandlePointer sdlHandle)
    {
        SDL_RenderPresent(sdlHandle->sdlRenderer);
    }
}
