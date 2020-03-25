#pragma once

#include <cstdint>

#include "Handle.hpp"

namespace creamyLib {
    class Color;

    namespace math {
        struct Vector2;
    }
}

namespace creamyLib::impl
{
    void DrawRect(const LibHandlePointer& libHandle, const math::Vector2& position, const math::Vector2& size, const Color& color, bool isFill = true);
}
