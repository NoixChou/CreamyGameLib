#include "Engine/Actor/Component/Primitive/2D/PrimitiveRendererComponent.hpp"

#include "../../InternalLib/include/DrawPrimitive.hpp"

#include "Application/Application.hpp"

#include "Engine/Actor/Actor.hpp"

namespace creamyLib::engine
{
    PrimitiveRendererComponent::PrimitiveRendererComponent(PrimitiveType primitive, const math::Vector2& size, const Color& color, const ComponentConfig& config)
        : Component(config), primitive(primitive), size(size), color(color), isFill(true)
    {
        implLibHandle_ = getOwner()->getApplication()->getLibHandle();
    }

    void PrimitiveRendererComponent::update(float deltaTime)
    {
        if(primitive == PrimitiveType::rect)
        {
            impl::DrawRect(implLibHandle_, getOwner()->getTransform().localPosition.toVector2(), size, color, isFill);
        }
    }
}
