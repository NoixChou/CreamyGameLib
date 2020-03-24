#include "ExternalImpl/SDL/Finalizer.hpp"

#include <SDL.h>

namespace creamyLib::impl
{
    void Finalize(const SDLHandlePointer sdlHandle)
    {
        if(!sdlHandle)
        {
            return;
        }

        if (sdlHandle->sdlRenderer)
        {
            SDL_DestroyRenderer(sdlHandle->sdlRenderer);
        }
        if (sdlHandle->sdlWindow)
        {
            SDL_DestroyWindow(sdlHandle->sdlWindow);
        }
        SDL_Quit();

        delete sdlHandle;
    }
}
