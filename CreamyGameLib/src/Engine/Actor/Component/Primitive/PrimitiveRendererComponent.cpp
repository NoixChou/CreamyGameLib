#include "Engine/Actor/Component/Primitive/2D/PrimitiveRendererComponent.hpp"

#include "Application/Application.hpp"

#include "Engine/Actor/Actor.hpp"

#include "DrawPrimitive.hpp"

namespace creamyLib::engine
{
    PrimitiveRendererComponent::PrimitiveRendererComponent(PrimitiveType primitive, const math::Vector2& size, const Color& color, const ComponentConfig& config)
        : Component(config), primitive(primitive), size(size), color(color), isFill(true)
    {
        implLibHandle = GetOwner()->GetApplication()->GetLibHandle();
    }

    void PrimitiveRendererComponent::Update(float deltaTime)
    {
        if(primitive == PrimitiveType::rect)
        {
            impl::DrawRect(implLibHandle, GetOwner()->GetTransform().position.ToVector2(), size, color, isFill);
        }
    }
}
