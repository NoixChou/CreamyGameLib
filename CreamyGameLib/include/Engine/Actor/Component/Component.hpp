#pragma once

#include <vector>

#include "Engine/EngineObject.hpp"
#include "Engine/Actor/Component/ComponentConfig.hpp"

namespace creamyLib::engine
{
    class Actor;

    class Component : public object::EngineObject
    {
    public:
        using ComponentPointer = Component*;
        using ComponentCollection = std::vector<Component*>;

        Component(const ComponentConfig& config);
        virtual ~Component();

        virtual void Update(float deltaTime) = 0;

        [[nodiscard]] int GetUpdatePriority() const;
        [[nodiscard]] Actor* GetOwner() const;
        [[nodiscard]] Application* GetApplication() const override;
    };
}
