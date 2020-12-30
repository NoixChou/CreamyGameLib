#include "Engine/Actor/Component/UserComponent.hpp"

#include <utility>

namespace creamyLib::engine
{
    UserComponent::UserComponent(UpdateMethod update, const ComponentConfig& config) : Component(config), updateMethod_(std::move(update))
    {
        
    }

    void UserComponent::update(float deltaTime)
    {
        updateMethod_(this, deltaTime);
    }
}
