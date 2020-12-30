#pragma once

#include "Vector2.hpp"

namespace creamyLib::math
{
    struct Vector3
    {
        float x;
        float y;
        float z;

        constexpr Vector3(const float x, const float y, const float z) : x(x), y(y), z(z) {}

        [[nodiscard]] Vector2 toVector2() const
        {
            return Vector2(x, y);
        }
    };
}
