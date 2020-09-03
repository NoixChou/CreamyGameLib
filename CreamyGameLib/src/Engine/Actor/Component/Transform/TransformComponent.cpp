#include "Engine/Actor/Component/Transform/TransformComponent.hpp"

namespace creamyLib::engine
{
    TransformComponent::TransformComponent(const math::Vector3& initPosition, const ComponentConfig& config)
        : Component(config), position(initPosition)
    {

    }

    void TransformComponent::Update(float deltaTime)
    {
        
    }
}
