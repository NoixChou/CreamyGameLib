#include "ExternalImpl/SDL/SDLEvent.hpp"

#include <SDL.h>

namespace creamyLib::impl
{
    bool WindowEvent::isQuit = false;

    void WindowEvent::Process()
    {
        SDL_Event l_Event;

        while(SDL_PollEvent(&l_Event))
        {
            switch (l_Event.type)
            {
            case SDL_QUIT:
                isQuit = true;
                break;
            }
        }
    }

    bool WindowEvent::IsQuit()
    {
        return isQuit;
    }
}
