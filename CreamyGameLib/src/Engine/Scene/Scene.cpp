#include "Engine/Scene/Scene.hpp"

#include "Engine/World/World.hpp"

namespace creamyLib::engine
{
    Scene::Scene(World* world) : owner(world)
    {
        owner->AddScene(this);
    }

    Scene::~Scene()
    {
        owner->RemoveScene(this);
    }

    void Scene::Update(float deltaTime)
    {
        UpdateActors(deltaTime);
    }

    void Scene::UpdateActors(float deltaTime)
    {
        for (auto l_Actor : actors)
        {
            l_Actor->InternalUpdate(deltaTime);
        }
    }

    void Scene::AddActor(Actor* actor)
    {
        if (!actor) return;
        actors.emplace_back(actor);
    }

    void Scene::RemoveActor(Actor* actor)
    {
        if (!actor) return;
        const auto l_ActorIterator = std::find(actors.begin(), actors.end(), actor);

        if (l_ActorIterator != actors.end())
        {
            actors.erase(l_ActorIterator);
        }
    }

    World* Scene::GetOwner() const
    {
        return owner;
    }

    Application* Scene::GetApplication() const
    {
        return owner->GetApplication();
    }
}
