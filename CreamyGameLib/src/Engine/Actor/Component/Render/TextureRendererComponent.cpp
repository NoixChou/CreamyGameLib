#include "Engine/Actor/Component/Render/TextureRendererComponent.hpp"

#include "Engine/Actor/Actor.hpp"
#include "Engine/Resource/Texture.hpp"
#include "Resource/TextureResource.hpp"

#include "DrawResource.hpp"

namespace creamyLib::engine
{
    TextureRendererComponent::TextureRendererComponent(resource::Texture* texture, const math::Vector2& size, const ComponentConfig& config)
        : Component(config), texture(texture), size(size)
    {
        implLibHandle_ = getOwner()->getApplication()->getLibHandle();
    }

    void TextureRendererComponent::update(float deltaTime)
    {
        if (!texture) return;

        auto l_Scale = getOwner()->getTransform().scale.toVector2();
        auto l_Resource = texture->getResource();
        impl::DrawTexture2D(implLibHandle_, l_Resource, getOwner()->getTransform().position.toVector2(), math::Vector2(size.x / l_Resource.width * l_Scale.x, size.y / l_Resource.height * l_Scale.y));
    }
}
