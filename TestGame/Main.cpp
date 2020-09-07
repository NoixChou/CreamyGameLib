#include <iostream>

#include "Application/Application.hpp"

#include "Engine/Actor/Component/Primitive/2D/PrimitiveRendererComponent.hpp"
#include "Engine/Actor/Component/Render/TextureRendererComponent.hpp"
#include "Engine/Actor/Component/UserComponent.hpp"
#include "Engine/Actor/Actor.hpp"
#include "Engine/Resource/ResourceManager.hpp"
#include "Engine/Scene/Scene.hpp"
#include "Engine/World/World.hpp"
#include "Engine/World/WorldConfiguration.hpp"

#include "Exception/Resource/ResourceLoadFailedException.hpp"

using namespace creamyLib;

void MoveActor(engine::UserComponent* component, float deltaTime, float moveSpeed)
{
    component->GetOwner()->GetTransform().position.x += moveSpeed * deltaTime;
}

int main(int argc, char** argv)
{
    auto l_Game = Application::Create(ApplicationConfig{ "TestGame", 1024, 768 });

    auto l_World = engine::World(&l_Game, engine::WorldConfiguration{ Color(255, 255, 255) });
    auto l_Scene = engine::Scene({ &l_World });
    auto l_RedBoxActor = engine::Actor({{ &l_Scene }});
    auto l_BlueBoxActor = engine::Actor({{ &l_Scene}});

    // 図形レンダラーコンポーネント
    auto l_RedBox = engine::PrimitiveRendererComponent(
        engine::PrimitiveRendererComponent::PrimitiveType::rect,
        math::Vector2(100, 100),
        Color(255, 0, 0, 120),
        { { &l_RedBoxActor } }
    );
    auto l_BlueBox = engine::PrimitiveRendererComponent(
        engine::PrimitiveRendererComponent::PrimitiveType::rect,
        math::Vector2(100, 100),
        Color(0, 0, 255, 120),
        { { &l_BlueBoxActor } }
    );

    // 移動コンポーネント
    auto l_RedBoxMove = engine::UserComponent([](engine::UserComponent* component, float deltaTime) { MoveActor(component, deltaTime, 40.f); }, {{ &l_RedBoxActor }});
    auto l_BlueBoxMove = engine::UserComponent([](engine::UserComponent* component, float deltaTime) { MoveActor(component, deltaTime, 45.f); }, {{ &l_BlueBoxActor }});

    // テクスチャレンダラーコンポーネント
    engine::resource::Texture* l_Texture;
    try {
        l_Texture = engine::resource::ResourceManager::GetInstance()->GetResourceTextureFromFile("test.png");
    }catch(exception::ResourceLoadFailedException& e)
    {
        std::cout << "read error: texture \"" << e.GetFileName() << "\"" << std::endl;
        std::cout << e.what() << std::endl;

        return 0;
    }
    auto l_RedBoxTexture = engine::TextureRendererComponent(
        l_Texture,
        math::Vector2(100, 100),
        { {&l_RedBoxActor } }
    );

    l_Game.Start(&l_World);
    l_Game.Quit();

    return 0;
}
