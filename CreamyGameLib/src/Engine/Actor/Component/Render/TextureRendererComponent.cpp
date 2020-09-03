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
        implLibHandle = GetOwner()->GetApplication()->GetLibHandle();
    }

    void TextureRendererComponent::Update(float deltaTime)
    {
        if (!texture) return;

        auto l_Scale = GetOwner()->GetTransform().scale.ToVector2();
        auto l_Resource = texture->GetResource();
        impl::DrawTexture2D(implLibHandle, l_Resource, GetOwner()->GetTransform().position.ToVector2(), math::Vector2(size.x / l_Resource.width * l_Scale.x, size.y / l_Resource.height * l_Scale.y));
    }
}
