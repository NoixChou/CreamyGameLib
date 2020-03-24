#include "ExternalImpl/SDL/Initializer.hpp"
#include "ExternalImpl/SDL/SDLConfig.hpp"

#include <SDL.h>

#include "ExternalImpl/SDL/Finalizer.hpp"

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

        SDL_Renderer* l_Renderer = SDL_CreateRenderer(l_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        if(!l_Renderer)
        {
            Finalize(new SDLHandle{ l_Window, nullptr });
            return SDLMessage("Fail: SDL Create Renderer", false);
        }

        SDL_SetRenderDrawColor(l_Renderer, 0, 0, 255, 255);

        return SDLMessage("", true, new SDLHandle{ l_Window, l_Renderer });
    }
}
