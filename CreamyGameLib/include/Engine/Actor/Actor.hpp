#pragma once

#include <vector>

#include "Component/Transform/TransformComponent.hpp"
#include "Engine/EngineObject.hpp"
#include "Engine/Actor/ActorConfig.hpp"

namespace creamyLib
{
    class Application;
}

namespace creamyLib::engine
{
    struct ActorConfig;
    class Scene;

    class Actor : public object::EngineObject
    {

    protected:
        TransformComponent transform_;
        std::vector<Component*> components_;

    public:
        using ActorPointer = Actor*;
        using ActorCollection = std::vector<Actor*>;

        Actor(const ActorConfig& config);
        virtual ~Actor();

        void internalUpdate(float deltaTime); // 最初に呼ばれる
        void updateComponents(float deltaTime);

        virtual void update(float deltaTime) {}

        void addComponent(Component* component);
        void removeComponent(Component* component);

        [[nodiscard]] TransformComponent& getTransform();
        [[nodiscard]] Scene* getOwner() const;
        [[nodiscard]] Application* getApplication() const override;
    };
}
