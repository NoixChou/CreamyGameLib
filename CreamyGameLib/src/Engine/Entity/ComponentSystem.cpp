#include "Engine/Entity/ComponentSystem.hpp"

#include "Engine/Entity/World.hpp"

namespace creamyLib::engine::ecs
{
    Application* ComponentSystem::getApplication() const
    {
        return world_->getApplication();
    }

    ComponentSystem::ComponentSystem(World* world): world_(world)
    {
    }
}
