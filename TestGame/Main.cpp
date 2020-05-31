#include "Application/Application.hpp"

#include "Engine/Actor/Component/Primitive/2D/PrimitiveRendererComponent.hpp"
#include "Engine/Actor/Component/UserComponent.hpp"
#include "Engine/Actor/Actor.hpp"
#include "Engine/Scene/Scene.hpp"
#include "Engine/World/World.hpp"
#include "Engine/World/WorldConfiguration.hpp"


void MoveActor(creamyLib::engine::UserComponent* component, float deltaTime, float moveSpeed)
{
    float a = component->GetOwner()->GetTransform().position.x;
    component->GetOwner()->GetTransform().position.x += moveSpeed * deltaTime;
}

int main(int argc, char** argv)
{
    auto game = creamyLib::Application::Create(creamyLib::ApplicationConfig{ "TestGame", 1024, 768 });

    auto l_World = creamyLib::engine::World(&game, creamyLib::engine::WorldConfiguration{});
    auto l_Scene = creamyLib::engine::Scene({ &l_World });
    auto l_RedBoxActor = creamyLib::engine::Actor({ &l_Scene });
    auto l_BlueBoxActor = creamyLib::engine::Actor({ &l_Scene });

    // 図形レンダラーコンポーネント
    auto l_RedBox = creamyLib::engine::PrimitiveRendererComponent(
        creamyLib::engine::PrimitiveRendererComponent::PrimitiveType::rect,
        creamyLib::math::Vector2(50, 50),
        creamyLib::Color(255, 0, 0, 120),
        {{ &l_RedBoxActor }}
    );
    auto l_BlueBox = creamyLib::engine::PrimitiveRendererComponent(
        creamyLib::engine::PrimitiveRendererComponent::PrimitiveType::rect,
        creamyLib::math::Vector2(50, 50),
        creamyLib::Color(0, 0, 255, 120),
        {{ &l_BlueBoxActor }}
    );

    // 移動コンポーネント
    auto l_RedBoxMove = creamyLib::engine::UserComponent([](creamyLib::engine::UserComponent* component, float deltaTime) { MoveActor(component, deltaTime, 40.f); }, {{ &l_RedBoxActor }});
    auto l_BlueBoxMove = creamyLib::engine::UserComponent([](creamyLib::engine::UserComponent* component, float deltaTime) { MoveActor(component, deltaTime, 45.f); }, {{ &l_BlueBoxActor }});

    game.Start(&l_World);
    game.Quit();

    return 0;
}
