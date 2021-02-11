#include "Engine/Entity/Entity.hpp"

namespace creamyLib::engine::ecs
{
    std::size_t Entity::getHash(std::size_t seed, std::size_t value)
    {
        return value + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }

    void Entity::updateHash()
    {
        id_ = getHash(index_, getHash(worldId_, poolId_));
    }

    Entity::Entity(std::size_t worldId, std::size_t poolId, std::size_t index): id_(0), worldId_(worldId), poolId_(poolId), index_(index)
    {
        updateHash();
    }

    std::size_t Entity::getId() const
    {
        return id_;
    }

    std::size_t Entity::getWorldId() const
    {
        return worldId_;
    }

    std::size_t Entity::getPoolId() const
    {
        return poolId_;
    }

    std::size_t Entity::getIndex() const
    {
        return index_;
    }

    bool Entity::operator==(const Entity& rhs) const
    {
        return id_ == rhs.id_;
    }
}
