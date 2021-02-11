#include <utility>

#include "Engine/Entity/ComponentPool.hpp"

namespace creamyLib::engine::ecs
{
    ComponentPool::ComponentPool(std::size_t id, typeInfo::DataTypeSet poolType, std::size_t capacity) : id_(id), reservedCount_(0), pool_(std::move(poolType), capacity) { }

    typeInfo::DataTypeSet ComponentPool::getPoolType() const
    {
        return pool_.getPoolType();
    }

    std::size_t ComponentPool::getId() const
    {
        return id_;
    }

    std::size_t ComponentPool::getSize() const
    {
        return pool_.getSize();
    }

    std::size_t ComponentPool::getCapacity() const
    {
        return pool_.getCapacity();
    }

    void ComponentPool::resize(std::size_t capacity)
    {
        pool_.resize(capacity);
    }

    std::size_t ComponentPool::addReserve()
    {
        return reservedCount_++;
    }

    void ComponentPool::removeComponents(std::size_t index)
    {
        pool_.remove(index);
    }
}
