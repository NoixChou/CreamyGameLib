#pragma once

#include <vector>

#include "Engine/EngineObject.hpp"

namespace creamyLib::engine
{
    class World;
    class Actor;

    class Scene : public object::EngineObject
    {
    protected:
        std::vector<Actor*> actors_;

    public:
        using ScenePointer = Scene*;
        using SceneCollection = std::vector<Scene*>;

        Scene(const object::EngineObjectConfig& config);
        ~Scene();

        void update(float deltaTime);
        void updateActors(float deltaTime);

        void addActor(Actor* actor);
        void removeActor(Actor* actor);

        [[nodiscard]] World* getOwner() const;
        [[nodiscard]] Application* getApplication() const override;
    };
}
