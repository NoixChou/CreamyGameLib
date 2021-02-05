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
        
        SDL_Window* window = SDL_CreateWindow(libConfig.windowTitle.c_str(), libConfig.windowPosX, libConfig.windowPosY, libConfig.windowWidth, libConfig.windowHeight, libConfig.windowFlags);

        if(!window)
        {
            return nullptr;
        }

        SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        if(!renderer)
        {
            Finalize(new LibHandle{ window, nullptr });
            return nullptr;
        }

        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        std::cout << "SDL initialized" << std::endl;

        return new LibHandle{ window, renderer };
    }
}

#endif
