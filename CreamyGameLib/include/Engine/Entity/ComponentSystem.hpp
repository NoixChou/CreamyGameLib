#pragma once
#include "World.hpp"

namespace creamyLib::engine::ecs
{
    class World;

    class ComponentSystem
    {
    private:
        template <std::size_t Index, std::size_t I, class... Ts>
        struct at_c_impl;

        template <std::size_t Index, std::size_t I, class T, class... Rest>
        struct at_c_impl< Index, I, T, Rest... >
        {
            using type = typename at_c_impl< Index, I + 1, Rest... >::type;
        };

        template <std::size_t Index, class T, class... Rest>
        struct at_c_impl< Index, Index, T, Rest... >
        {
            using type = T;
        };

        template <std::size_t Index, class... Ts>
        struct at_c
        {
            using type = typename at_c_impl< Index, 0, Ts... >::type;
        };


        World* world_;

        template<typename FuncType, typename ...Types>
        static void foreachImpl(typeInfo::DataTypePool* pool, FuncType&& function, typeInfo::DataTypeChunk<Types> ...args)
        {
            for(std::size_t i = 0; i < pool->getSize(); i++)
            {
                function(args[i]...);
            }
        }

        template<typename ...Args>
        static decltype(auto) getDataTypeChunks(typeInfo::DataTypePool* pool)
        {
            return std::make_tuple<typeInfo::DataTypeChunk<Args>...>(pool->getDataChunk<Args>()...);
        }

    protected:
        [[nodiscard]] Application* getApplication() const;

        template<typename ...Types, typename FuncType>
        constexpr void foreach(FuncType&& function)
        {
            typeInfo::DataTypeSet types = typeInfo::DataTypeSet::make<Types...>();
            std::vector<typeInfo::DataTypePool*> pools = world_->getComponentPools(types);

            for (typeInfo::DataTypePool* pool : pools)
            {
                std::apply(foreachImpl<FuncType, Types...>, std::tuple_cat(std::make_tuple(pool, function), getDataTypeChunks<Types...>(pool)));
            }
        }

    public:
        explicit ComponentSystem(World* world);
        virtual ~ComponentSystem() = default;

        virtual void update() = 0;
    };
}
