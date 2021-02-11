#include <iostream>
#include <random>

#include "../InternalLib/include/DrawPrimitive.hpp"
#include "Application/Application.hpp"

//#include "Engine/Actor/Component/Primitive/2D/PrimitiveRendererComponent.hpp"
//#include "Engine/Actor/Component/Render/TextureRendererComponent.hpp"
//#include "Engine/Actor/Component/UserComponent.hpp"
//#include "Engine/Actor/Actor.hpp"
#include "Engine/Entity/ComponentSystem.hpp"
#include "Engine/Resource/ResourceManager.hpp"
#include "Engine/Resource/Asset.hpp"
#include "Engine/Resource/Texture.hpp"
//#include "Engine/Scene/Scene.hpp"
#include "Engine/Time/DeltaTime.hpp"
//#include "Engine/World/World.hpp"
//#include "Engine/World/WorldConfiguration.hpp"

#include "Exception/Resource/ResourceLoadFailedException.hpp"
#include "Math/Vector3.hpp"
#include "Util/Color.hpp"

using namespace creamyLib;

struct Transform
{
    math::Vector3 position;
    math::Vector3 rotation;
    math::Vector3 scale;
};

struct TestComponent
{
    float speed;
    float lifeTime;
};

struct Rect
{
    math::Vector2 size;
    Color color;
};

struct Scene
{
    Color backgroundColor;
};

void makeEntity(engine::ecs::World* world)
{
    std::random_device randDevice;
    std::mt19937 mt(randDevice());
    std::uniform_int_distribution<> rand(10, 200);

    auto transform = Transform{
        .position = math::Vector3(rand(mt) * 2, rand(mt), rand(mt) * 3),
        .rotation = math::Vector3(rand(mt), rand(mt), rand(mt)),
        .scale = math::Vector3(rand(mt),rand(mt),rand(mt))
    };
    auto test = TestComponent{ .speed = rand(mt) / 2.f, .lifeTime = 10.f };
    auto rect = Rect{ .size = math::Vector2(rand(mt), rand(mt)), .color = Color(rand(mt), rand(mt), rand(mt)) };

    world->queueMakeEntity(transform, test, rect);
}

class TestSystem : public engine::ecs::ComponentSystem
{
public:
    using ComponentSystem::ComponentSystem;

    void update() override
    {
        foreachWithEntity<Transform, TestComponent>(
            [this](engine::ecs::Entity& entity, Transform& transform, TestComponent& test)
            {
                test.lifeTime -= engine::DeltaTime::get();
                if (transform.position.x > 1000.f)
                {
                    getWorld()->destroyEntity(entity);
                    makeEntity(getWorld());
                }
                transform.position.x += test.speed * engine::DeltaTime::get();
            }
        );
    }
};

class DrawSceneSystem : public engine::ecs::ComponentSystem
{
    using ComponentSystem::ComponentSystem;

    void update() override
    {
        foreach<Scene>([this](Scene& scene)
            {
                impl::RenderService::clearBuffer(getApplication()->getLibHandle(), scene.backgroundColor);
            }
        );
    }
};

class DrawRectSystem : public engine::ecs::ComponentSystem
{
public:
    using ComponentSystem::ComponentSystem;

    void update() override
    {
        foreach<Transform, Rect>([this](Transform& transform, Rect& rect)
            {
                impl::DrawRect(this->getApplication()->getLibHandle(), transform.position.toVector2(), rect.size, rect.color, true);
            }
        );
    }
};

int main(int argc, char** argv)
{
    auto game = Application::create(ApplicationConfig{ "TestGame", 1200, 900, false });

    engine::ecs::World world(&game);

    world.addSystem<DrawSceneSystem>();
    world.addSystem<TestSystem>();
    world.addSystem<DrawRectSystem>();

    world.queueMakeEntity(Scene{ .backgroundColor = Color(0, 0, 0) });

    const auto entityNum = 2000;

    world.setComponentPoolCapacity<Transform, TestComponent, Rect>(entityNum);

    for (auto i = 0; i < entityNum; i++)
    {
        makeEntity(&world);
    }

    game.start(&world);

    game.quit();

    return 0;
}
