#pragma once

#include "WorldConfiguration.hpp"

#include "Engine/Scene/Scene.hpp"

namespace creamyLib {
    class Application;
}

namespace creamyLib::engine
{
    class World
    {
    private:
        Scene::SceneCollection scenes;

    protected:
        Application* application;
        WorldConfiguration configuration;

    public:
        World(Application* app, WorldConfiguration config = {});

        void Update(float deltaTime);

        void UpdateScenes(float deltaTime);

        void AddScene(Scene* scene);
        void RemoveScene(Scene* scene);
        
        void Destroy();

        Application* GetApplication() const;
    };
}
