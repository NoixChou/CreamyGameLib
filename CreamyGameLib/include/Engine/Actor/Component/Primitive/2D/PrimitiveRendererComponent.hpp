#pragma once

#include "Engine/Actor/Component/Component.hpp"

#include "Math/Vector2.hpp"
#include "Util/Color.hpp"

namespace creamyLib::engine
{
    class PrimitiveRendererComponent : public Component
    {
    public:
        enum class PrimitiveType
        {
            rect,
        };

        PrimitiveType primitive;
        math::Vector2 size;
        Color color;
        bool isFill;

        PrimitiveRendererComponent(PrimitiveType primitive, const math::Vector2& size, const Color& color, const ComponentConfig& config);

        void Update(float deltaTime) override;
    };
}
