#pragma once

namespace creamyLib::math
{
    struct Vector2
    {
        float x;
        float y;

        constexpr Vector2(float x, float y) : x(x), y(y) {}
    };
}
