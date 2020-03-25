#pragma once

#include "Vector2.hpp"

namespace creamyLib::math
{
    struct Vector3
    {
        float x;
        float y;
        float z;

        constexpr Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
        Vector2 ToVector2() const
        {
            return Vector2(x, y);
        }
    };
}
