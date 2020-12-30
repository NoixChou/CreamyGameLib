#include "Engine/Actor/Component/Component.hpp"

#include "Engine/Actor/Actor.hpp"
#include "Engine/Actor/Component/ComponentConfig.hpp"

namespace creamyLib::engine
{
    Component::Component(const ComponentConfig& config) : EngineObject(static_cast<const object::EngineObjectConfig&>(config))
    {
        if (config.isInject)
            getOwner()->addComponent(this);
    }

    Component::~Component()
    {
        getOwner()->removeComponent(this);
    }

    int Component::getUpdatePriority() const
    {
        return this->config_.priority;
    }

    Actor* Component::getOwner() const
    {
        return dynamic_cast<Actor*>(config_.owner);
    }

    Application* Component::getApplication() const
    {
        return getOwner()->getApplication();
    }
}
