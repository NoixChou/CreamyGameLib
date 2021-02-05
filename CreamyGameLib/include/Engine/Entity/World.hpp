#pragma once

#include <memory>
#include <vector>

#include "EntityPool.hpp"
#include "Util/DataType/DataTypePool.hpp"

namespace creamyLib {
    class Application;
}

namespace creamyLib::engine::ecs
{
    class ComponentSystem;
    class ComponentGroup;

    class World
    {
    private:
        static std::size_t worldCount_;
        std::size_t id_;

        Application* application_;

        EntityPool entityPool_;
        std::vector<typeInfo::DataTypePool> componentPools_;
        std::vector<std::unique_ptr<ComponentSystem>> systems_;

        std::tuple<typeInfo::DataTypePool&, std::size_t> getAndAddComponentPool(const typeInfo::DataTypeSet& types);

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

        Entity& makeEntity(typeInfo::DataTypeSet&& types);

        template<typename ...Types>
        Entity& makeEntity(Types&& ...components)
        {
            auto& entity = makeEntity<Types...>();
            componentPools_[entity.getPoolId()].add(components...);

            return entity;
        }

        template<typename Type>
        void addComponent(Entity& entity, Type& component)
        {
            if(!this->contains(entity))
            {
                return;
            }

            componentPools_[entity.getPoolId()].set(entity.getIndex(), component);
        }

        template<typename Type>
        void addSystem()
        {
            systems_.emplace_back(new Type(this));
        }

        template<typename ...Types>
        std::vector<typeInfo::DataTypePool*> getComponentPools()
        {
            return this->getComponentPools(typeInfo::DataTypeSet::make<Types...>());
        }

        std::vector<typeInfo::DataTypePool*> getComponentPools(const typeInfo::DataTypeSet& types);

        bool contains(Entity& entity) const;
    };
}
