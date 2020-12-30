#pragma once

#include <tuple>

namespace creamyLib::math
{
    struct Vector2
    {
        float x;
        float y;

        constexpr Vector2(const float x, const float y) : x(x), y(y) {}

        [[nodiscard]] std::tuple<int, int> toInteger() const
        {
            return std::make_tuple(static_cast<int>(x), static_cast<int>(y));
        }
    };
}
