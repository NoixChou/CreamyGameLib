#include "Engine/Actor/Actor.hpp"

#include "Engine/Scene/Scene.hpp"

namespace creamyLib::engine
{
    Actor::Actor(const ActorConfiguration& config) : EngineObject(config), transform_(TransformComponent(math::Vector3(0, 0, 0), { {this}, false}))
    {
        getOwner()->addActor(this);
    }

    Actor::~Actor()
    {
        getOwner()->removeActor(this);
        components_.clear();
    }

    void Actor::internalUpdate(float deltaTime)
    {
        updateComponents(deltaTime);
        update(deltaTime);
    }

    void Actor::updateComponents(float deltaTime)
    {
        for(const auto& component : components_)
        {
            component->update(deltaTime);
        }
    }

    void Actor::addComponent(Component* component)
    {
        if (!component) return;
        components_.emplace_back(component);
    }

    void Actor::removeComponent(Component* component)
    {
        if (!component) return;

        if (const auto componentIterator = std::find(components_.begin(), components_.end(), component);
            componentIterator != components_.end())
        {
            components_.erase(componentIterator);
        }
    }

    TransformComponent& Actor::getTransform()
    {
        return transform_;
    }

    Scene* Actor::getOwner() const
    {
        return dynamic_cast<Scene*>(config_.owner);
    }

    Application* Actor::getApplication() const
    {
        return getOwner()->getApplication();
    }
}
