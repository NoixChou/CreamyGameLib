#include "ExternalImpl/SDL/SDLEvent.hpp"

#include <SDL.h>

namespace creamyLib::impl
{
    bool SDLEvent::isQuit = false;

    void SDLEvent::Process()
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

    bool SDLEvent::IsQuit()
    {
        return isQuit;
    }
}
