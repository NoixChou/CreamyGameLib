#include "Engine/World/World.hpp"

#include "Application/Application.hpp"
#include "Engine/Scene/Scene.hpp"

namespace creamyLib::engine
{
    World::World(Application* app, const WorldConfiguration config) : EngineObject({ nullptr }), application(app), configuration(config)
    {
        
    }

    World::~World()
    {
        scenes.clear();
    }

    void World::Update(float deltaTime)
    {
        impl::RenderService::ClearBuffer(GetApplication()->GetLibHandle(), configuration.backgroundColor);
        UpdateScenes(deltaTime);
    }

    void World::UpdateScenes(float deltaTime)
    {
        for (const auto& l_Scene : scenes)
        {
            l_Scene->Update(deltaTime);
        }
    }

    void World::AddScene(Scene* scene)
    {
        if (!scene) return;
        scenes.emplace_back(scene);
    }

    void World::RemoveScene(Scene* scene)
    {
        if (!scene) return;
        const auto l_SceneIterator = std::find(scenes.begin(), scenes.end(), scene);

        if (l_SceneIterator != scenes.end())
        {
            scenes.erase(l_SceneIterator);
        }
    }

    Application* World::GetApplication() const
    {
        return application;
    }
}
