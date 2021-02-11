#include "Engine/Entity/EntityPool.hpp"

#include <execution>

namespace creamyLib::engine::ecs
{
    Entity& EntityPool::addEntity(const Entity& entity)
    {
        entities_.emplace(entity.getId(), entity);
        return entities_.at(entity.getId());
    }

    void EntityPool::destroyEntity(const Entity& entity)
    {
        const Entity erased = entity;

        if(const std::size_t erasedCount = entities_.erase(entity.getId()); erasedCount == 0)
        {
            return;
        }

        std::ranges::for_each(entities_, [&erased, this](EntitiesMap::value_type& pair)
            {
                Entity& entity = pair.second;
                if (erased.getPoolId() != entity.getPoolId() || erased.getIndex() >= entity.getIndex())
                {
                    return;
                }

                --entity.index_;
                entity.updateHash();
                entities_.insert_or_assign(entity.getId(), entity);
            }
        );
    }

    Entity* EntityPool::getEntity(std::size_t id)
    {
        if(!entities_.contains(id))
        {
            return nullptr;
        }

        return &entities_.at(id);
    }
}
