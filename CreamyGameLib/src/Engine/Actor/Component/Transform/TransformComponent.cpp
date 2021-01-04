#include "Engine/Actor/Component/Transform/TransformComponent.hpp"

namespace creamyLib::engine
{
    TransformComponent::TransformComponent(const math::Vector3& initPosition, const ComponentConfig& config)
        : Component(config), localPosition(initPosition)
    {

    }

    void TransformComponent::update(float deltaTime)
    {
        
    }

    math::Vector3 TransformComponent::getPosition() const
    {
        return localPosition;
    }
}
