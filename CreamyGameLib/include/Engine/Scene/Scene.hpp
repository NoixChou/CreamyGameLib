#pragma once

#include <vector>

#include "Engine/Actor/Actor.hpp"

namespace creamyLib::engine
{
    class World;

    class Scene
    {
    protected:
        World* owner;
        Actor::ActorCollection actors;

    public:
        using SceneCollection = std::vector<Scene*>;

        Scene(World* world);
        ~Scene();

        void Update(float deltaTime);
        void UpdateActors(float deltaTime);

        void AddActor(Actor* actor);
        void RemoveActor(Actor* actor);

        World* GetOwner() const;
        Application* GetApplication() const;
    };
}
