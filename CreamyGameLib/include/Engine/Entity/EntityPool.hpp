#pragma once

#include <vector>

#include "Entity.hpp"

namespace creamyLib::engine::ecs
{
    class EntityPool
    {
    private:
        std::vector<Entity> entities_;

    public:
        Entity& addEntity(const Entity& entity);
        void destroyEntity(const Entity& entity);
    };
}
