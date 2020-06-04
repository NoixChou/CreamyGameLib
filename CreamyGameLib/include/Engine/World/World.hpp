#pragma once

#include <vector>

#include "WorldConfiguration.hpp"

#include "Engine/EngineObject.hpp"

namespace creamyLib {
    class Application;
}

namespace creamyLib::engine
{
    class Scene;

    class World : public object::EngineObject
    {
    private:
        std::vector<Scene*> scenes;

    protected:
        Application* application;
        WorldConfiguration configuration;

    public:
        World(Application* app, WorldConfiguration config = {});
        ~World();

        void Update(float deltaTime);

        void UpdateScenes(float deltaTime);

        void AddScene(Scene* scene);
        void RemoveScene(Scene* scene);

        [[nodiscard]] Application* GetApplication() const override;
    };
}
