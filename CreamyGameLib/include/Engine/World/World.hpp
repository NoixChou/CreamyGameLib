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
        std::vector<Scene*> scenes_;

    protected:
        Application* application_;
        WorldConfiguration configuration_;

    public:
        World(Application* app, const WorldConfiguration& config = {});
        ~World();

        void update(float deltaTime);

        void updateScenes(float deltaTime);

        void addScene(Scene* scene);
        void removeScene(Scene* scene);

        [[nodiscard]] Application* getApplication() const override;
    };
}
