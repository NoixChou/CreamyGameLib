#include <iostream>

#include "Application/Application.hpp"

#include "Engine/Actor/Component/Primitive/2D/PrimitiveRendererComponent.hpp"
#include "Engine/Actor/Component/UserComponent.hpp"

void MoveActor(creamyLib::engine::UserComponent* component, float deltaTime, float moveSpeed)
{
    component->GetOwner()->GetTransform()->position.x += moveSpeed * deltaTime;
}

int main(int argc, char** argv)
{
    auto game = creamyLib::Application::Create(creamyLib::ApplicationConfig{ "TestGame", 1024, 768 });

    auto l_World = new creamyLib::engine::World(&game, creamyLib::engine::WorldConfiguration{});
    auto l_Scene = new creamyLib::engine::Scene(l_World);
    auto l_RedBoxActor = new creamyLib::engine::Actor(l_Scene);
    auto l_BlueBoxActor = new creamyLib::engine::Actor(l_Scene);

    // 図形レンダラーコンポーネント
    auto l_RedBox = creamyLib::engine::PrimitiveRendererComponent(
        creamyLib::engine::PrimitiveRendererComponent::PrimitiveType::rect,
    creamyLib::math::Vector2(50, 50),
        creamyLib::Color(255, 0, 0, 120),
        l_RedBoxActor
    );
    auto l_BlueBox = creamyLib::engine::PrimitiveRendererComponent(
        creamyLib::engine::PrimitiveRendererComponent::PrimitiveType::rect,
        creamyLib::math::Vector2(50, 50),
        creamyLib::Color(0, 0, 255, 120),
        l_BlueBoxActor
    );

    // 移動コンポーネント
    auto l_RedBoxMove = creamyLib::engine::UserComponent([](creamyLib::engine::UserComponent* component, float deltaTime) { MoveActor(component, deltaTime, 40.f); }, l_RedBoxActor);
    auto l_BlueBoxMove = creamyLib::engine::UserComponent([](creamyLib::engine::UserComponent* component, float deltaTime) { MoveActor(component, deltaTime, 45.f); }, l_BlueBoxActor);

    game.Start(l_World);
    game.Quit();

    //delete l_RedBoxMove;
    //delete l_RedBox;
    delete l_RedBoxActor;
    //delete l_BlueBoxMove;
    //delete l_BlueBox;
    delete l_BlueBoxActor;
    delete l_Scene;
    delete l_World;

    return 0;
}
