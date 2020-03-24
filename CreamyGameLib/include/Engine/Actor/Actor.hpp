#pragma once

#include <vector>

#include "Engine/Actor/Component/Component.hpp"

namespace creamyLib::engine
{
    class Scene;

    class Actor
    {
    protected:
        Scene* owner;
        Component::ComponentCollection components;

    public:
        using ActorCollection = std::vector<Actor*>;

        Actor(Scene* scene);
        ~Actor();

        void InternalUpdate(float deltaTime); // 最初に呼ばれる
        void UpdateComponents(float deltaTime);

        virtual void Update(float deltaTime) {}

        void AddComponent(Component* component);
        void RemoveComponent(Component* component);
    };
}
