#pragma once

#include <SDL/SDL_hints.h>
#include <string>

namespace creamyLib::impl
{
    struct LibConfig
    {
        std::string windowTitle;
        int windowPosX;
        int windowPosY;
        int windowWidth;
        int windowHeight;
        Uint32 windowFlags;
    };
}
