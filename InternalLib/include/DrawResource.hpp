#pragma once

#include "Handle.hpp"

namespace creamyLib {
    class Color;

    namespace math {
        struct Vector2;
    }
}

namespace creamyLib::impl
{
    namespace resource {
        struct TextureResource;
    }

    void DrawTexture2D(const LibHandlePointer& libHandle, const resource::TextureResource& texture, const math::Vector2& position, const math::Vector2& scale);
}
