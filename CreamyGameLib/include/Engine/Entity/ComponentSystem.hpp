#pragma once

#include <algorithm>
#include <execution>
#include <iostream>
#include <thread>

#include "World.hpp"

namespace creamyLib::engine::ecs
{
    class World;

    class ComponentSystem
    {
    private:
        World* world_;

        template<typename FuncType, typename ...Types>
        static void foreachParallelWithEntityImpl(World* world, ComponentPool* pool, FuncType&& function, typeInfo::DataTypeChunk<Types> ...args)
        {
            using TupleType = std::tuple<Entity&, Types&...>;
            std::vector<TupleType> componentSets;

            for(std::size_t i = 0; i < pool->getSize(); i++)
            {
                if (auto entity = world->getEntity(Entity(world->getId(), pool->getId(), i)); entity)
                {
                    componentSets.emplace_back(std::tie<Entity&, Types&...>(*entity, args[i]...));
                }
            }

            std::for_each(std::execution::par, componentSets.begin(), componentSets.end(), [&function](TupleType& arg)
                {
                    std::apply(function, arg);
                }
            );
        }

        template<typename FuncType, typename ...Types>
        static void foreachParallelWithoutEntityImpl(World* world, ComponentPool* pool, FuncType&& function, typeInfo::DataTypeChunk<Types> ...args)
        {
            using TupleType = std::tuple<Types&...>;
            std::vector<TupleType> componentSets;

            for (std::size_t i = 0; i < pool->getSize(); i++)
            {
                componentSets.emplace_back(std::tie<Types&...>(args[i]...));
            }

            std::for_each(std::execution::par, componentSets.begin(), componentSets.end(), [&function](TupleType& arg)
                {
                    std::apply(function, arg);
                }
            );
        }

        template<typename FuncType, typename ...Types>
        static void foreachWithEntityImpl(World* world, ComponentPool* pool, FuncType&& function, typeInfo::DataTypeChunk<Types> ...args)
        {
            for (std::size_t i = 0; i < pool->getSize(); i++)
            {
                if (auto entity = world->getEntity(Entity(world->getId(), pool->getId(), i)); entity)
                {
                    function(*entity, args[i]...);
                }
            }
        }

        template<typename FuncType, typename ...Types>
        static void foreachWithoutEntityImpl(World* world, ComponentPool* pool, FuncType&& function, typeInfo::DataTypeChunk<Types> ...args)
        {
            for (std::size_t i = 0; i < pool->getSize(); i++)
            {
                function(args[i]...);
            }
        }

        template<typename ...Args>
        static decltype(auto) getDataTypeChunks(ComponentPool* pool)
        {
            return std::make_tuple<typeInfo::DataTypeChunk<Args>...>(pool->getComponentChunk<Args>()...);
        }

        template<typename ...Types, typename ImplFuncType, typename FuncType>
        void foreachImpl(ImplFuncType&& implFunc, FuncType&& function)
        {
            typeInfo::DataTypeSet types = typeInfo::DataTypeSet::make<Types...>();
            std::vector<ComponentPool*> pools = world_->getComponentPools(types);

            for (ComponentPool* pool : pools)
            {
                std::apply(implFunc, std::tuple_cat(std::make_tuple(world_), std::make_tuple(pool, function), getDataTypeChunks<Types...>(pool)));
            }
        }

    protected:
        [[nodiscard]] Application* getApplication() const;

        template<typename ...Types, typename FuncType>
        constexpr void foreach(FuncType&& function)
        {
            foreachImpl<Types...>(foreachWithoutEntityImpl<FuncType, Types...>, function);
        }

        template<typename ...Types, typename FuncType>
        constexpr void foreachWithEntity(FuncType&& function)
        {
            foreachImpl<Types...>(foreachWithEntityImpl<FuncType, Types...>, function);
        }

        template<typename ...Types, typename FuncType>
        void foreachParallel(FuncType&& function)
        {
            foreachImpl<Types...>(foreachParallelWithoutEntityImpl<FuncType, Types...>, function);
        }

        template<typename ...Types, typename FuncType>
        void foreachParallelWithEntity(FuncType&& function)
        {
            foreachImpl<Types...>(foreachParallelWithEntityImpl<FuncType, Types...>, function);
        }

    public:
        explicit ComponentSystem(World* world);
        virtual ~ComponentSystem() = default;

        virtual void update() = 0;

        [[nodiscard]] World* getWorld() const;
    };
}
