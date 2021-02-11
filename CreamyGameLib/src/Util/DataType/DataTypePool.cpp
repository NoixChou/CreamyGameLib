#include <utility>

#include "Util/DataType/DataTypePool.hpp"

namespace creamyLib::typeInfo
{
    std::unique_ptr<std::byte[]> DataTypePool::getNewMemory(std::size_t capacity) const
    {
        return std::make_unique<std::byte[]>(poolType_.getMemorySize() * capacity);
    }

    void DataTypePool::resize(std::size_t capacity)
    {
        if(capacity_ >= capacity)
        {
            return;
        }

        auto resized = getNewMemory(capacity);

        for (auto&& type : poolType_)
        {
            const auto typeOffset = poolType_.getOffset(type);
            std::memcpy(resized.get() + typeOffset * capacity, std::bit_cast<void*>(getDataChunkOffset(type)), type.getSize() * size_);
        }

        buffer_ = std::move(resized);
        capacity_ = capacity;
    }

    void DataTypePool::remove(std::size_t index)
    {
        if(index >= size_)
        {
            return;
        }

        for (auto&& type : poolType_)
        {
            std::memmove(
                std::bit_cast<void*>(getDataChunkOffset(type) + type.getSize() * index),
                std::bit_cast<void*>(getDataChunkOffset(type) + type.getSize() * (index + 1)),
                type.getSize() * (size_ - index - 1)
            );
        }

        size_--;
    }

    std::size_t DataTypePool::getSize() const
    {
        return size_;
    }

    std::size_t DataTypePool::getCapacity() const
    {
        return capacity_;
    }

    DataTypeSet DataTypePool::getPoolType() const
    {
        return poolType_;
    }

    std::size_t DataTypePool::getDataChunkOffset(const DataType& type) const
    {
        return std::bit_cast<std::size_t>(buffer_.get() + poolType_.getOffset(type) * capacity_);
    }

    DataTypePool::DataTypePool(DataTypeSet poolType, std::size_t capacity)
        : buffer_(nullptr), size_(0), capacity_(capacity), poolType_(std::move(poolType))
    {
        buffer_ = getNewMemory(capacity_);
    }
}
