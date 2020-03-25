#pragma once

#include "SDLHandle.hpp"

namespace creamyLib::impl
{
    struct LibConfig;
    LibHandlePointer Initialize(const LibConfig& sdlConfig);
}
