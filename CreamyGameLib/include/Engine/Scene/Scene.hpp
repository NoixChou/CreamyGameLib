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
        std::vector<Actor*> actors;

    public:
        using ScenePointer = Scene*;
        using SceneCollection = std::vector<Scene*>;

        Scene(const object::EngineObjectConfig& config);
        ~Scene();

        void Update(float deltaTime);
        void UpdateActors(float deltaTime);

        void AddActor(Actor* actor);
        void RemoveActor(Actor* actor);

        [[nodiscard]] World* GetOwner() const;
        [[nodiscard]] Application* GetApplication() const override;
    };
}
