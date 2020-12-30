#include "Engine/World/World.hpp"

#include "Application/Application.hpp"
#include "Engine/Scene/Scene.hpp"

namespace creamyLib::engine
{
    World::World(Application* app, const WorldConfiguration& config) : EngineObject({ nullptr }), application_(app), configuration_(config) {}

    World::~World()
    {
        scenes_.clear();
    }

    void World::update(float deltaTime)
    {
        impl::RenderService::clearBuffer(getApplication()->getLibHandle(), configuration_.backgroundColor);
        updateScenes(deltaTime);
    }

    void World::updateScenes(float deltaTime)
    {
        for (const auto& scene : scenes_)
        {
            scene->update(deltaTime);
        }
    }

    void World::addScene(Scene* scene)
    {
        if (!scene) return;
        scenes_.emplace_back(scene);
    }

    void World::removeScene(Scene* scene)
    {
        if (!scene) return;
        const auto sceneIterator = std::find(scenes_.begin(), scenes_.end(), scene);

        if (sceneIterator != scenes_.end())
        {
            scenes_.erase(sceneIterator);
        }
    }

    Application* World::getApplication() const
    {
        return application_;
    }
}
