#pragma once

#include "Engine/Actor/Component/Component.hpp"

#include <functional>

namespace creamyLib::engine
{
    class UserComponent : public Component
    {
    public:
        using UpdateMethod = std::function<void(UserComponent*, float)> ;

    protected:
        UpdateMethod updateMethod;

    public:
        UserComponent(UpdateMethod update, Actor* owner, int updatePriority = 50);

        void Update(float deltaTime) override;
    };
}
