#pragma once

#include "Engine/Actor/Component/Transform/TransformComponent.hpp"
#include "Engine/Actor/Component/Component.hpp"

#include <vector>

namespace creamyLib
{
    class Application;
}

namespace creamyLib::engine
{
    class Scene;

    class Actor
    {
    protected:
        Scene* owner;
        TransformComponent* transform;
        Component::ComponentCollection components;

    public:
        using ActorCollection = std::vector<Actor*>;

        Actor(Scene* scene);
        virtual ~Actor();

        void InternalUpdate(float deltaTime); // 最初に呼ばれる
        void UpdateComponents(float deltaTime);

        virtual void Update(float deltaTime) {}

        void AddComponent(Component* component);
        void RemoveComponent(Component* component);

        TransformComponent* GetTransform() const;
        Scene* GetOwner() const;
        Application* GetApplication() const;
    };
}
