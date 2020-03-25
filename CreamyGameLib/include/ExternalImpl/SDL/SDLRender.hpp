#pragma once
#include "SDLHandle.hpp"

namespace creamyLib::impl
{
    class RenderService
    {
    public:
        static void ClearBuffer(const LibHandlePointer sdlHandle);
        static void PresentBuffer(const LibHandlePointer sdlHandle);
    };
}
