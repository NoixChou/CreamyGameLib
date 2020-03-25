#pragma once

#include <vector>

namespace creamyLib::engine
{
    class Actor;

    class Component
    {
    protected:
        Actor* owner;
        int updatePriority;

    public:
        using ComponentCollection = std::vector<Component*>;

        Component(Actor* owner, int updatePriority = 50);
        virtual ~Component();

        virtual void Update(float deltaTime) = 0;

        int GetUpdatePriority() const;
        Actor* GetOwner() const;
    };
}
