#include "Engine/Entity/World.hpp"

#include "Engine/Entity/ComponentSystem.hpp"

namespace creamyLib::engine::ecs
{
    std::size_t World::worldCount_ = 0;

    ComponentPool& World::getAndAddComponentPool(const typeInfo::DataTypeSet& types)
    {
        for(std::size_t i = 0; auto&& pool : componentPools_)
        {
            if(pool.getPoolType() == types)
            {
                return pool;
            }

            i++;
        }

        componentPools_.emplace_back(ComponentPool(componentPools_.size(), types));

        return componentPools_[componentPools_.size() - 1];
    }

    World::World(Application* application): id_(worldCount_++), application_(application)
    {
    }

    World::~World() = default;

    void World::update()
    {
        makeQueuedEntities();

        for (auto&& system : systems_)
        {
            system->update();
        }

        destroyQueuedEntities();
    }

    Application* World::getApplication() const
    {
        return application_;
    }

    std::size_t World::getId() const
    {
        return id_;
    }

    void World::setComponentPoolCapacity(typeInfo::DataTypeSet&& types, std::size_t capacity)
    {
        auto& pool = getAndAddComponentPool(types);
        pool.resize(capacity);
    }

    Entity& World::makeEntity(const typeInfo::DataTypeSet& types)
    {
        auto& pool = getAndAddComponentPool(types);
        
        return entityPool_.addEntity(Entity(id_, pool.getId(), pool.addReserve()));
    }

    void World::makeQueuedEntities()
    {
        for (auto&& queue : entityMakeQueues_)
        {
            queue();
        }

        entityMakeQueues_.clear();
    }

    void World::destroyEntity(Entity& entity)
    {
        if(!this->contains(entity))
        {
            return;
        }

        entityDestroyQueues_.emplace_back(entity);
    }

    void World::destroyQueuedEntities()
    {
        for (auto&& entity : entityDestroyQueues_)
        {
            componentPools_[entity.get().getPoolId()].removeComponents(entity.get().getIndex());
            entityPool_.destroyEntity(entity);
        }

        entityDestroyQueues_.clear();
    }

    Entity* World::getEntity(const Entity& entity)
    {
        return entityPool_.getEntity(entity.getId());
    }

    std::vector<ComponentPool*> World::getComponentPools(const typeInfo::DataTypeSet& types)
    {
        std::vector<ComponentPool*> result;

        for (auto&& pool : componentPools_)
        {
            if (pool.getPoolType().contains(types))
            {
                result.emplace_back(&pool);
            }
        }

        return result;
    }

    bool World::contains(Entity& entity) const
    {
        return entity.getWorldId() == id_ && entity.getPoolId() < componentPools_.size();
    }
}
