#pragma once

#include <string>

#include "Util/Color.hpp"

namespace creamyLib
{
    struct ApplicationConfig
    {
        std::string applicationTitle;
        int windowWidth;
        int windowHeight;
        bool isFullscreen;
    };
}
