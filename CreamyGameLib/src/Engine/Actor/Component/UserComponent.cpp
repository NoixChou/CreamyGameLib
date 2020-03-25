#include "Engine/Actor/Component/UserComponent.hpp"

#include <utility>

namespace creamyLib::engine
{
    UserComponent::UserComponent(UpdateMethod update, Actor* owner, int updatePriority) : Component(owner, updatePriority), updateMethod(std::move(update))
    {
        
    }

    void UserComponent::Update(float deltaTime)
    {
        updateMethod(this, deltaTime);
    }
}
