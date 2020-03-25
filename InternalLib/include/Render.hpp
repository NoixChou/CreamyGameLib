#pragma once

#include "Handle.hpp"

namespace creamyLib::impl
{
    class RenderService
    {
    public:
        static void ClearBuffer(const LibHandlePointer libHandle);
        static void PresentBuffer(const LibHandlePointer libHandle);
    };
}
