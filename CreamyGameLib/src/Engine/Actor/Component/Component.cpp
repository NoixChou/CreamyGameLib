#include "Engine/Actor/Component/Component.hpp"

#include "Engine/Actor/Actor.hpp"
#include "Engine/Actor/Component/ComponentConfig.hpp"

namespace creamyLib::engine
{
    Component::Component(const ComponentConfig& config) : EngineObject(static_cast<const object::EngineObjectConfig&>(config))
    {
        if (config.isInject)
            GetOwner()->AddComponent(this);
    }

    Component::~Component()
    {
        GetOwner()->RemoveComponent(this);
    }

    int Component::GetUpdatePriority() const
    {
        return this->config.priority;
    }

    Actor* Component::GetOwner() const
    {
        return dynamic_cast<Actor*>(config.owner);
    }

    Application* Component::GetApplication() const
    {
        return GetOwner()->GetApplication();
    }
}
