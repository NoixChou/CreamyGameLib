#include "Engine/Scene/Scene.hpp"

#include "Engine/World/World.hpp"
#include "Engine/Actor/Actor.hpp"

namespace creamyLib::engine
{
    Scene::Scene(const object::EngineObjectConfig& config) : EngineObject(config)
    {
        getOwner()->addScene(this);
    }

    Scene::~Scene()
    {
        getOwner()->removeScene(this);
        actors_.clear();
    }

    void Scene::update(float deltaTime)
    {
        updateActors(deltaTime);
    }

    void Scene::updateActors(float deltaTime)
    {
        for (auto* const actor : actors_)
        {
            actor->internalUpdate(deltaTime);
        }
    }

    void Scene::addActor(Actor* actor)
    {
        if (!actor) return;
        actors_.emplace_back(actor);
    }

    void Scene::removeActor(Actor* actor)
    {
        if (!actor) return;
        const auto actorIterator = std::find(actors_.begin(), actors_.end(), actor);

        if (actorIterator != actors_.end())
        {
            actors_.erase(actorIterator);
        }
    }

    World* Scene::getOwner() const
    {
        return dynamic_cast<World*>(config_.owner);
    }

    Application* Scene::getApplication() const
    {
        return getOwner()->getApplication();
    }
}
