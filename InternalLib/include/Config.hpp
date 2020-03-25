#pragma once

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
        uint32_t windowFlags;
    };
}
