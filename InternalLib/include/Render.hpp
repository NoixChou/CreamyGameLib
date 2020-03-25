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
        static void ClearBuffer(const LibHandlePointer& libHandle, const Color& color);
        static void PresentBuffer(const LibHandlePointer& libHandle);
    };
}
