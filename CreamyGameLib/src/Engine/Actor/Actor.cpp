#include "Engine/Actor/Actor.hpp"

#include "Engine/Scene/Scene.hpp"

namespace creamyLib::engine
{
    Actor::Actor(Scene* scene) : owner(scene)
    {
        owner->AddActor(this);
    }

    Actor::~Actor()
    {
        owner->RemoveActor(this);
    }

    void Actor::InternalUpdate(float deltaTime)
    {
        UpdateComponents(deltaTime);
        Update(deltaTime);
    }

    void Actor::UpdateComponents(float deltaTime)
    {
        for(auto l_Component : components)
        {
            l_Component->Update(deltaTime);
        }
    }

    void Actor::AddComponent(Component* component)
    {
        if (!component) return;
        components.emplace_back(component);
    }

    void Actor::RemoveComponent(Component* component)
    {
        if (!component) return;
        const auto l_ComponentIterator = std::find(components.begin(), components.end(), component);

        if (l_ComponentIterator != components.end())
        {
            components.erase(l_ComponentIterator);
        }
    }
}
