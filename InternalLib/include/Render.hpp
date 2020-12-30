#pragma once

#include "Handle.hpp"

namespace creamyLib {
    class Color;
}

namespace creamyLib::impl
{
    class RenderService
    {
    public:
        static void clearBuffer(const LibHandlePointer& libHandle, const Color& color);
        static void presentBuffer(const LibHandlePointer& libHandle);
    };
}
