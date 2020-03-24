#include "Engine/World/World.hpp"

#include "Application/Application.hpp"

namespace creamyLib::engine
{
    World::World(creamyLib::Application* app, WorldConfiguration config) : application(app), configuration(config)
    {
        
    }

    void World::Update(float deltaTime)
    {
        
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

    void World::Destroy()
    {
        
    }
}
