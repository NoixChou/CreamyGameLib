#pragma once

#include <SDL_hints.h>
#include <string>

namespace creamyLib::impl
{
    struct SDLConfig
    {
        std::string windowTitle;
        int windowPosX;
        int windowPosY;
        int windowWidth;
        int windowHeight;
        Uint32 windowFlags;
    };
}
