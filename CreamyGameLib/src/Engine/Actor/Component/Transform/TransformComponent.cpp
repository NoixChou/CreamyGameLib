#include "Engine/Actor/Component/Transform/TransformComponent.hpp"

namespace creamyLib::engine
{
    TransformComponent::TransformComponent(const math::Vector3& initPosition, Actor* owner, int updatePriority) : Component(owner, updatePriority), position(initPosition)
    {
        
    }

    void TransformComponent::Update(float deltaTime)
    {
        
    }
}
