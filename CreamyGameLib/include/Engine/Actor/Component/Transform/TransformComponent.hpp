#pragma once

#include "Engine/Actor/Component/Component.hpp"

#include "Math/Vector3.hpp"

namespace creamyLib::engine
{
    class TransformComponent : public Component
    { 
    public:
        math::Vector3 localPosition;
        math::Vector3 rotation {0, 0, 0};
        math::Vector3 scale {1.f, 1.f, 1.f};

        TransformComponent(const math::Vector3& initPosition, const ComponentConfig& config);

        void update(float deltaTime) override;

        [[nodiscard]] math::Vector3 getPosition() const;
    };
}
