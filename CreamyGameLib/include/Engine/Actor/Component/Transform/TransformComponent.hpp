#pragma once

#include "Engine/Actor/Component/Component.hpp"

#include "Math/Vector3.hpp"

namespace creamyLib::engine
{
    class TransformComponent : public Component
    {
    public:
        math::Vector3 position;

        TransformComponent(const math::Vector3& initPosition, const ComponentConfig& config);

        void Update(float deltaTime) override;
    };
}
