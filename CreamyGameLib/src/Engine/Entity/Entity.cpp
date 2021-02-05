#include "Engine/Entity/Entity.hpp"

namespace creamyLib::engine::ecs
{
    std::size_t Entity::getHash(std::size_t seed, std::size_t value)
    {
        return value + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }

    Entity::Entity(std::size_t worldId, std::size_t poolId, std::size_t index): id_(getHash(getHash(worldId, poolId), index)), worldId_(worldId), poolId_(poolId), index_(index)
    {
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
