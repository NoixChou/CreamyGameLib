#pragma once

#include <memory>

#include "Engine/Actor/Component/Component.hpp"
#include "Engine/Resource/ResourcePrefab.hpp"

#include "Math/Vector2.hpp"

namespace creamyLib::engine
{
    namespace resource
    {
        class AssetTexture;
        class Texture;
    }

    class TextureRendererComponent : public Component
    {
    private:
        impl::LibHandlePointer implLibHandle_ = nullptr;

    public:
        resource::ResourcePrefab<resource::Texture> texture;
        math::Vector2 size;

        TextureRendererComponent(resource::ResourcePrefab<resource::Texture> texture, const math::Vector2& size, const ComponentConfig& config);

        void update(float deltaTime) override;
    };
}
