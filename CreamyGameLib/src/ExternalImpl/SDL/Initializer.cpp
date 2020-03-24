#include "ExternalImpl/SDL/Initializer.hpp"
#include "ExternalImpl/SDL/SDLConfig.hpp"

#include <SDL.h>

namespace creamyLib::impl
{
    SDLMessage Initialize(const SDLConfig& sdlConfig)
    {
        if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
        {
            return SDLMessage("Fail: SDL Initialize", false);
        }

        SDL_Window* l_Window = SDL_CreateWindow(sdlConfig.windowTitle.c_str(), sdlConfig.windowPosX, sdlConfig.windowPosY, sdlConfig.windowWidth, sdlConfig.windowHeight, sdlConfig.windowFlags);

        if(!l_Window)
        {
            return SDLMessage("Fail: SDL Create Window", false);
        }

        return SDLMessage("", true, new SDLHandle{ l_Window, nullptr });
    }
}
