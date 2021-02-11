#pragma once
#include <vector>

#include "DataType.hpp"

namespace creamyLib::typeInfo
{
    class DataTypeSet
    {
    private:
        std::vector<DataType> types_;
        std::size_t memorySize_ = 0;

        template<typename HeadType, typename ...TailTypes>
        constexpr void addTypes()
        {
            this->addType(DataType::make<HeadType>());

            if constexpr (sizeof...(TailTypes) > 0)
            {
                this->addTypes<TailTypes...>();
            }
        }

    public:
        template<typename ...Types>
        static DataTypeSet make()
        {
            DataTypeSet map;
            map.addTypes<Types...>();

            return map;
        }

        void addType(const DataType& type);

        [[nodiscard]] std::size_t getMemorySize() const;
        [[nodiscard]] std::size_t getSize() const;

        template<typename Type>
        [[nodiscard]] std::size_t getOffset() const
        {
            return this->getOffset(DataType::make<Type>());
        }

        [[nodiscard]] std::size_t getOffset(const DataType& type) const;

        bool operator==(const DataTypeSet& rhs) const;
        bool operator!=(const DataTypeSet& rhs) const;

        template<typename ...Types>
        [[nodiscard]] bool contains() const
        {
            return this->contains(DataTypeSet::make<Types...>());
        }

        // typeSet ==contains=> (this) = true
        [[nodiscard]] bool contains(const DataTypeSet& typeSet) const;

        template<typename Type>
        [[nodiscard]] bool contains() const
        {
            return this->contains(DataType::make<Type>());
        }

        bool contains(const DataType& type);

        std::vector<DataType>::iterator begin();
        std::vector<DataType>::iterator end();
    };
}
