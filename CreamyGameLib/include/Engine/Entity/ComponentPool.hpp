#pragma once

#include "Util/DataType/DataTypePool.hpp"
#include "Util/DataType/DataTypeSet.hpp"

namespace creamyLib::engine::ecs
{
    class ComponentPool
    {
    private:
        std::size_t id_;
        std::size_t reservedCount_;
        typeInfo::DataTypePool pool_;

    public:
        ComponentPool(std::size_t id, typeInfo::DataTypeSet poolType, std::size_t capacity = 1);

        [[nodiscard]] typeInfo::DataTypeSet getPoolType() const;
        [[nodiscard]] std::size_t getId() const;

        [[nodiscard]] std::size_t getSize() const;
        [[nodiscard]] std::size_t getCapacity() const;

        void resize(std::size_t capacity);
        [[nodiscard]] std::size_t addReserve();

        template<typename ...Types>
        std::size_t addComponents(Types& ...data)
        {
            return pool_.add<Types...>(data...);
        }

        template<typename Type>
        void setComponent(std::size_t index, Type& data)
        {
            pool_.set(index, data);
        }

        void removeComponents(std::size_t index);

        template<typename Type>
        typeInfo::DataTypeChunk<Type> getComponentChunk()
        {
            return pool_.getDataChunk<Type>();
        }
    };
}
