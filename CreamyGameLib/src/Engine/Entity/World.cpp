#include "Engine/Entity/World.hpp"

#include "Engine/Entity/ComponentSystem.hpp"

namespace creamyLib::engine::ecs
{
    std::size_t World::worldCount_ = 0;

    std::tuple<typeInfo::DataTypePool&, std::size_t> World::getAndAddComponentPool(const typeInfo::DataTypeSet& types)
    {
        for(std::size_t i = 0; auto&& pool : componentPools_)
        {
            if(pool.getPoolType() == types)
            {
                return std::make_tuple(std::ref(pool), i);
            }

            i++;
        }

        componentPools_.emplace_back(typeInfo::DataTypePool(types));

        return std::make_tuple(std::ref(componentPools_[componentPools_.size() - 1]), componentPools_.size() - 1);
    }

    World::World(Application* application): id_(worldCount_++), application_(application)
    {
    }

    World::~World() = default;

    void World::update()
    {
        for (auto&& system : systems_)
        {
            system->update();
        }
    }

    Application* World::getApplication() const
    {
        return application_;
    }

    void World::setComponentPoolCapacity(typeInfo::DataTypeSet&& types, std::size_t capacity)
    {
        auto [pool, poolId] = getAndAddComponentPool(types);
        pool.resize(capacity);
    }

    Entity& World::makeEntity(typeInfo::DataTypeSet&& types)
    {
        auto [pool, poolId] = getAndAddComponentPool(types);
        pool.resize(pool.getSize() + 1);
        return entityPool_.addEntity(Entity(id_, poolId, pool.getSize()));
    }

    std::vector<typeInfo::DataTypePool*> World::getComponentPools(const typeInfo::DataTypeSet& types)
    {
        std::vector<typeInfo::DataTypePool*> result;

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
