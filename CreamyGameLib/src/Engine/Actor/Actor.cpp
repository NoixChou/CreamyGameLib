#include "Engine/Actor/Actor.hpp"

#include "Engine/Scene/Scene.hpp"

namespace creamyLib::engine
{
    Actor::Actor(const ActorConfig& config) : EngineObject(config), transform(TransformComponent(math::Vector3(0, 0, 0), { {this}, false}))
    {
        GetOwner()->AddActor(this);
    }

    Actor::~Actor()
    {
        GetOwner()->RemoveActor(this);
        components.clear();
    }

    void Actor::InternalUpdate(float deltaTime)
    {
        UpdateComponents(deltaTime);
        Update(deltaTime);
    }

    void Actor::UpdateComponents(float deltaTime)
    {
        for(const auto& l_Component : components)
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

    TransformComponent& Actor::GetTransform()
    {
        return transform;
    }

    Scene* Actor::GetOwner() const
    {
        return dynamic_cast<Scene*>(config.owner);
    }

    Application* Actor::GetApplication() const
    {
        return GetOwner()->GetApplication();
    }
}
