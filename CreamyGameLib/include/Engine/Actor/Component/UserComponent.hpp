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
        UpdateMethod updateMethod_;

    public:
        UserComponent(UpdateMethod update, const ComponentConfig& config);

        void update(float deltaTime) override;
    };
}
