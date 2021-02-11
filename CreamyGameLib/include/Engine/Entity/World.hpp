#pragma once

#include <functional>
#include <memory>
#include <vector>

#include "ComponentPool.hpp"
#include "EntityPool.hpp"

#include "Util/DataType/DataTypePool.hpp"

namespace creamyLib {
    class Application;
}

namespace creamyLib::engine::ecs
{
    class ComponentSystem;
    class ComponentPool;

    class World
    {
    private:
        static std::size_t worldCount_;
        std::size_t id_;

        Application* application_;

        EntityPool entityPool_;
        std::vector<std::function<void()>> entityMakeQueues_;
        std::vector<std::reference_wrapper<Entity>> entityDestroyQueues_;
        std::vector<ComponentPool> componentPools_;
        std::vector<std::unique_ptr<ComponentSystem>> systems_;

        ComponentPool& getAndAddComponentPool(const typeInfo::DataTypeSet& types);

        template<typename HeadType, typename ...TailTypes>
        void addComponentsImpl(Entity& entity, HeadType& headComponent, TailTypes& ...tailComponents)
        {
            this->addComponent(entity, headComponent);

            if constexpr (sizeof...(TailTypes) > 0)
            {
                this->addComponentsImpl(tailComponents...);
            }
        }

    public:
        World(Application* application);
        ~World();

        void update();

        [[nodiscard]] Application* getApplication() const;
        [[nodiscard]] std::size_t getId() const;

        template<typename ...Types>
        void setComponentPoolCapacity(std::size_t capacity)
        {
            this->setComponentPoolCapacity(typeInfo::DataTypeSet::make<Types...>(), capacity);
        }

        void setComponentPoolCapacity(typeInfo::DataTypeSet&& types, std::size_t capacity);

        template<typename ...Types>
        Entity& makeEntity()
        {
            return this->makeEntity(typeInfo::DataTypeSet::make<Types...>());
        }

        Entity& makeEntity(const typeInfo::DataTypeSet& types);

        template<typename ...Types>
        void queueMakeEntity(const Types& ...components)
        {
            auto dataTypeSet = typeInfo::DataTypeSet::make<Types...>();

            entityMakeQueues_.emplace_back([this, dataTypeSet, components...]()
            {
                Entity& entity = this->makeEntity(dataTypeSet);
                componentPools_[entity.getPoolId()].addComponents(components...);
            });
        }

        void makeQueuedEntities();

        void destroyEntity(Entity& entity);
        void destroyQueuedEntities();

        Entity* getEntity(const Entity& entity);

        template<typename Type>
        void addComponent(Entity& entity, Type& component)
        {
            if(!this->contains(entity))
            {
                return;
            }

            componentPools_[entity.getPoolId()].setComponent(entity.getIndex(), component);
        }

        template<typename Type>
        void addSystem()
        {
            systems_.emplace_back(new Type(this));
        }

        template<typename ...Types>
        std::tuple<Types&...> getComponents(Entity& entity)
        {
            assert(this->contains(entity));

            return std::tie(componentPools_[entity.getPoolId()].getComponentChunk<Types>()[entity.getIndex()]...);
        }

        template<typename ...Types>
        std::vector<ComponentPool*> getComponentPools()
        {
            return this->getComponentPools(typeInfo::DataTypeSet::make<Types...>());
        }

        std::vector<ComponentPool*> getComponentPools(const typeInfo::DataTypeSet& types);

        bool contains(Entity& entity) const;
    };
}
