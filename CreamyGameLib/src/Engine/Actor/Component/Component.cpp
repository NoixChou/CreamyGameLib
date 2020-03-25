#include "Engine/Actor/Component/Component.hpp"

#include "Engine/Actor/Actor.hpp"

namespace creamyLib::engine
{
    Component::Component(Actor* owner, int updatePriority) : owner(owner), updatePriority(updatePriority)
    {
        this->owner->AddComponent(this);
    }

    Component::~Component()
    {
        this->owner->RemoveComponent(this);
    }

    int Component::GetUpdatePriority() const
    {
        return this->updatePriority;
    }

    Actor* Component::GetOwner() const
    {
        return owner;
    }
}
