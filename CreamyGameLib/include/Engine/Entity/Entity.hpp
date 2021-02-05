#pragma once

#include <cstddef>

namespace creamyLib::engine::ecs
{
    class Entity
    {
    private:
        std::size_t id_;
        std::size_t worldId_;
        std::size_t poolId_;
        std::size_t index_;

        static std::size_t getHash(std::size_t seed, std::size_t value);

    public:
        explicit Entity(std::size_t worldId, std::size_t poolId, std::size_t index);

        [[nodiscard]] std::size_t getId() const;
        [[nodiscard]] std::size_t getWorldId() const;
        [[nodiscard]] std::size_t getPoolId() const;
        [[nodiscard]] std::size_t getIndex() const;

        bool operator==(const Entity& rhs) const;
    };
}
