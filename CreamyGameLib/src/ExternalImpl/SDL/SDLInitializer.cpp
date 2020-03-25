#include "ExternalImpl/SDL/SDLInitializer.hpp"
#include "ExternalImpl/SDL/SDLConfig.hpp"

#include <SDL.h>

#include "ExternalImpl/SDL/SDLFinalizer.hpp"

namespace creamyLib::impl
{
    LibHandlePointer Initialize(const LibConfig& sdlConfig)
    {
        if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
        {
            return nullptr;
        }

        SDL_Window* l_Window = SDL_CreateWindow(sdlConfig.windowTitle.c_str(), sdlConfig.windowPosX, sdlConfig.windowPosY, sdlConfig.windowWidth, sdlConfig.windowHeight, sdlConfig.windowFlags);

        if(!l_Window)
        {
            return nullptr;
        }

        SDL_Renderer* l_Renderer = SDL_CreateRenderer(l_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        if(!l_Renderer)
        {
            Finalize(new LibHandle{ l_Window, nullptr });
            return nullptr;
        }

        SDL_SetRenderDrawColor(l_Renderer, 0, 0, 0, 255);

        return new LibHandle{ l_Window, l_Renderer };
    }
}
