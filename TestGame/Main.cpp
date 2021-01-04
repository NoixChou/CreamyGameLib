#include <iostream>

#include "Application/Application.hpp"

#include "Engine/Actor/Component/Primitive/2D/PrimitiveRendererComponent.hpp"
#include "Engine/Actor/Component/Render/TextureRendererComponent.hpp"
#include "Engine/Actor/Component/UserComponent.hpp"
#include "Engine/Actor/Actor.hpp"
#include "Engine/Resource/ResourceManager.hpp"
#include "Engine/Resource/Asset.hpp"
#include "Engine/Resource/Texture.hpp"
#include "Engine/Scene/Scene.hpp"
#include "Engine/World/World.hpp"
#include "Engine/World/WorldConfiguration.hpp"

#include "Exception/Resource/ResourceLoadFailedException.hpp"

using namespace creamyLib;

void MoveActor(engine::UserComponent* component, const float deltaTime, const float moveSpeed)
{
    component->getOwner()->getTransform().localPosition.x += moveSpeed * deltaTime;
}

int main(int argc, char** argv)
{
    auto game = Application::create(ApplicationConfig{ "TestGame", 1024, 768 });

    auto world = engine::World(&game, engine::WorldConfiguration{ Color(255, 255, 255) });
    auto scene = engine::Scene({ .owner = &world });
    auto redBoxActor = engine::Actor({{ &scene }});
    auto blueBoxActor = engine::Actor({{ &scene }});

    // 図形レンダラーコンポーネント
    auto redBox = engine::PrimitiveRendererComponent(
        engine::PrimitiveRendererComponent::PrimitiveType::rect,
        math::Vector2(100, 100),
        Color(255, 0, 0, 120),
        { { &redBoxActor } }
    );
    auto blueBox = engine::PrimitiveRendererComponent(
        engine::PrimitiveRendererComponent::PrimitiveType::rect,
        math::Vector2(100, 100),
        Color(0, 0, 255, 120),
        { { &blueBoxActor } }
    );

    // 移動コンポーネント
    auto redBoxMove = engine::UserComponent([](engine::UserComponent* component, const float deltaTime) { MoveActor(component, deltaTime, 40.f); }, {{ &redBoxActor }});
    auto blueBoxMove = engine::UserComponent([](engine::UserComponent* component, const float deltaTime) { MoveActor(component, deltaTime, 45.f); }, {{ &blueBoxActor }});

    // テクスチャレンダラーコンポーネント
    engine::resource::AssetTexture textureAsset({ { "img_test", "test.png" } });
    auto texture = engine::resource::ResourcePrefab<engine::resource::Texture>(textureAsset);

    try {
        texture = engine::resource::ResourceManager::getInstance()->getAssetResource(textureAsset);
    }catch(exception::ResourceLoadFailedException& exception)
    {
        std::cout << "read error: texture \"" << exception.getFileName() << "\"" << std::endl;
        std::cout << exception.what() << std::endl;

        return 0;
    }
    auto redBoxTexture = engine::TextureRendererComponent(
        texture,
        math::Vector2(100, 100),
        { {&redBoxActor } }
    );

    game.start(&world);
    game.quit();

    return 0;
}
