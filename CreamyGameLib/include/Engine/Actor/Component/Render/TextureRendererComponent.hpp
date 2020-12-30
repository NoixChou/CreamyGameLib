#pragma once

#include "Engine/Actor/Component/Component.hpp"

#include "Math/Vector2.hpp"
#include "Util/Color.hpp"

namespace creamyLib::engine
{
    namespace resource
    {
        class Texture;
    }

    class TextureRendererComponent : public Component
    {
    private:
        impl::LibHandlePointer implLibHandle_ = nullptr;

    public:
        resource::Texture* texture;
        math::Vector2 size;

        TextureRendererComponent(resource::Texture* texture, const math::Vector2& size, const ComponentConfig& config);

        void update(float deltaTime) override;
    };
}
