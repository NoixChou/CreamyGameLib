#pragma once

#include <unordered_map>

#include "Entity.hpp"

namespace creamyLib::engine::ecs
{
    class EntityPool
    {
    private:
        using EntitiesMap = std::unordered_map<std::size_t, Entity>;
        EntitiesMap entities_;

    public:
        Entity& addEntity(const Entity& entity);
        void destroyEntity(const Entity& entity);

        Entity* getEntity(std::size_t id);
    };
}
