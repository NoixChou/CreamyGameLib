#include <iostream>

#include "Application/Application.hpp"

#include "Engine/Actor/Component/Primitive/2D/PrimitiveRendererComponent.hpp"
#include "Engine/Actor/Component/UserComponent.hpp"

int main(int argc, char** argv)
{
    auto game = creamyLib::Application::Create(creamyLib::ApplicationConfig{ "TestGame", 1024, 768 });

    auto world = new creamyLib::engine::World(&game, creamyLib::engine::WorldConfiguration{});
    auto scene = new creamyLib::engine::Scene(world);
    auto actor = new creamyLib::engine::Actor(scene);

    // 図形レンダラーコンポーネント
    auto l_Primitive = new creamyLib::engine::PrimitiveRendererComponent(
        creamyLib::engine::PrimitiveRendererComponent::PrimitiveType::rect,
    creamyLib::math::Vector2(50, 50),
        creamyLib::Color(0, 0, 0),
        actor
    );

    // 移動コンポーネント
    auto l_Move = new creamyLib::engine::UserComponent([](creamyLib::engine::UserComponent* component, float deltaTime) {
        auto transform = component->GetOwner()->GetTransform();

        transform->position.x += 40.f * deltaTime;
        std::cout << "deltaTime: " << deltaTime << std::endl;
    }, actor);

    game.Start(world);
    game.Quit();

    delete l_Move;
    delete l_Primitive;
    delete actor;
    delete scene;
    delete world;

    return 0;
}
