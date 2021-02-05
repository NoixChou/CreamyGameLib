#include "Engine/Entity/EntityPool.hpp"

namespace creamyLib::engine::ecs
{
    Entity& EntityPool::addEntity(const Entity& entity)
    {
        return entities_.emplace_back(entity);
    }

    void EntityPool::destroyEntity(const Entity& entity)
    {
        std::erase(entities_, entity);
    }
}
