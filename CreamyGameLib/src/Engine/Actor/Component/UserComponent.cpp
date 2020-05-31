#include "Engine/Actor/Component/UserComponent.hpp"

#include <utility>

namespace creamyLib::engine
{
    UserComponent::UserComponent(UpdateMethod update, const ComponentConfig& config) : Component(config), updateMethod(std::move(update))
    {
        
    }

    void UserComponent::Update(float deltaTime)
    {
        updateMethod(this, deltaTime);
    }
}
