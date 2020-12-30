#ifdef CREAMY_USE_SDL

#include "Event.hpp"

#include "SDL.h"

namespace creamyLib::impl
{
    bool WindowEvent::isQuit_ = false;

    void WindowEvent::process()
    {
        SDL_Event sdlEvent;

        while(SDL_PollEvent(&sdlEvent))
        {
            switch (sdlEvent.type)
            {
            case SDL_QUIT:
                isQuit_ = true;
                break;
            default: ;
            }
        }
    }

    bool WindowEvent::isQuit()
    {
        return isQuit_;
    }
}

#endif
