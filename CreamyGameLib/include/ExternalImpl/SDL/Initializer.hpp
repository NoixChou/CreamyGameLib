#pragma once

#include "SDLMessage.hpp"

namespace creamyLib::impl
{
    struct SDLConfig;

    SDLMessage Initialize(const SDLConfig& sdlConfig);
}
