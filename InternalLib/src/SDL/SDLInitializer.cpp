#ifdef CREAMY_USE_SDL

#include "Initializer.hpp"
#include "Finalizer.hpp"
#include "Config.hpp"

#include <iostream>

#include "SDL.h"

namespace creamyLib::impl
{
    LibHandlePointer Initialize(const LibConfig& libConfig)
    {
        if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
        {
            return nullptr;
        }

        SDL_Window* l_Window = SDL_CreateWindow(libConfig.windowTitle.c_str(), libConfig.windowPosX, libConfig.windowPosY, libConfig.windowWidth, libConfig.windowHeight, libConfig.windowFlags);

        if(!l_Window)
        {
            return nullptr;
        }

        SDL_Renderer* l_Renderer = SDL_CreateRenderer(l_Window, -1, SDL_RENDERER_ACCELERATED);

        if(!l_Renderer)
        {
            Finalize(new LibHandle{ l_Window, nullptr });
            return nullptr;
        }

        SDL_SetRenderDrawBlendMode(l_Renderer, SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(l_Renderer, 0, 0, 0, 255);

        std::cout << "SDL initialized" << std::endl;

        return new LibHandle{ l_Window, l_Renderer };
    }
}

#endif
