#pragma once

#include <cstddef>
#include <memory>
#include <bit>
#include <cassert>
#include <iterator>

#include "DataTypeSet.hpp"

namespace creamyLib::typeInfo
{
    template<typename Type>
    class DataTypeChunk
    {
    private:
        Type* begin_;
        std::size_t size_;

    public:
        struct Iterator
        {
            using value_type = Type;
            using iterator_concept = std::contiguous_iterator_tag;

            Iterator(Type* pointer) : pointer_(pointer) {}

            constexpr Type* operator*() const
            {
                return pointer_;
            }

            constexpr Type* operator++()
            {
                return ++pointer_;
            }

            constexpr bool operator==(const Iterator& rhs) const
            {
                return pointer_ == rhs.pointer_;
            }

        private:
            Type* pointer_;
        };

        DataTypeChunk(): begin_(nullptr), size_(0) {}
        DataTypeChunk(Type* begin, std::size_t size): begin_(begin), size_(size) {}

        Type& operator[](const std::size_t index)
        {
            return begin_[index];
        }

        Iterator begin()
        {
            return Iterator(begin_);
        }

        Iterator end()
        {
            return Iterator(begin_ + size_);
        }
    };

    class DataTypePool
    {
    private:
        std::unique_ptr<std::byte[]> buffer_;
        std::size_t size_;
        std::size_t capacity_;
        DataTypeSet poolType_;

        [[nodiscard]] std::unique_ptr<std::byte[]> getNewMemory(std::size_t capacity) const;

        template<typename Type>
        [[nodiscard]] std::size_t getDataChunkOffset() const
        {
            return this->getDataChunkOffset(DataType::make<Type>());
        }

        [[nodiscard]] std::size_t getDataChunkOffset(const DataType& type) const;

        template<typename HeadType, typename ...TailTypes>
        void addData(HeadType& headData, TailTypes& ...data)
        {
            auto type = DataType::make<HeadType>();
            assert(poolType_.contains(type));

            std::memcpy(std::bit_cast<void*>(this->getDataChunkOffset(type) + type.getSize() * size_), &headData, sizeof(HeadType));

            if constexpr (sizeof...(TailTypes) > 0)
            {
                this->addData(data...);
            }
        }

    public:
        DataTypePool(DataTypeSet poolType, std::size_t capacity = 1);

        void resize(std::size_t capacity);

        template<typename ...Type>
        std::size_t add(Type& ...data)
        {
            if(size_ >= capacity_)
            {
                resize(size_ * 2);
            }

            this->addData(data...);

            return size_++;
        }

        template<typename Type>
        void set(std::size_t index, Type& data)
        {
            assert(index < capacity_);

            auto type = DataType::make<Type>();
            assert(poolType_.contains(type));

            if (index > size_)
            {
                size_ = index;
            }

            std::memcpy(this->getDataChunkOffset(type) + type.getSize() * index, &data, sizeof(Type));
        }

        void remove(std::size_t index);

        [[nodiscard]] std::size_t getSize() const;
        [[nodiscard]] std::size_t getCapacity() const;

        [[nodiscard]] DataTypeSet getPoolType() const;

        template<typename Type>
        DataTypeChunk<Type> getDataChunk()
        {
            return DataTypeChunk<Type>(std::bit_cast<Type*>(getDataChunkOffset<Type>()), size_);
        }
    };
}
