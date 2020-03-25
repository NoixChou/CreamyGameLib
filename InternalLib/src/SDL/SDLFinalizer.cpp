#ifdef CREAMY_USE_SDL

#include "Finalizer.hpp"

#include "SDL.h"

namespace creamyLib::impl
{
    void Finalize(const LibHandlePointer& libHandle)
    {
        if(!libHandle)
        {
            return;
        }

        if (libHandle->sdlRenderer)
        {
            SDL_DestroyRenderer(libHandle->sdlRenderer);
        }
        if (libHandle->sdlWindow)
        {
            SDL_DestroyWindow(libHandle->sdlWindow);
        }
        SDL_Quit();

        delete libHandle;
    }
}

#endif
