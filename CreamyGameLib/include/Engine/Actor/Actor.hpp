#pragma once

#include <vector>

#include "Component/Transform/TransformComponent.hpp"
#include "Engine/EngineObject.hpp"
#include "Engine/Actor/ActorConfig.hpp"

namespace creamyLib
{
    class Application;
}

namespace creamyLib::engine
{
    struct ActorConfig;
    class Scene;

    class Actor : public object::EngineObject
    {

    protected:
        TransformComponent transform;
        std::vector<Component*> components;

    public:
        using ActorPointer = Actor*;
        using ActorCollection = std::vector<Actor*>;

        Actor(const ActorConfig& config);
        virtual ~Actor();

        void InternalUpdate(float deltaTime); // 最初に呼ばれる
        void UpdateComponents(float deltaTime);

        virtual void Update(float deltaTime) {}

        void AddComponent(Component* component);
        void RemoveComponent(Component* component);

        [[nodiscard]] TransformComponent& GetTransform();
        [[nodiscard]] Scene* GetOwner() const;
        [[nodiscard]] Application* GetApplication() const override;
    };
}
