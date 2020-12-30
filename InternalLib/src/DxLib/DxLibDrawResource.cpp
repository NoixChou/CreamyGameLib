#ifdef CREAMY_USE_DXLIB

#include "DrawResource.hpp"

#include "Resource/TextureResource.hpp"

#include "../../../CreamyGameLib/include/Util/Color.hpp"
#include "../../../CreamyGameLib/include/Math/Vector2.hpp"

#include "DxLib.h"

namespace creamyLib::impl
{
    void DrawTexture2D(const LibHandlePointer& libHandle, const resource::TextureResource& texture, const math::Vector2& position, const math::Vector2& scale)
    {
        const auto [x, y] = position.toInteger();
        const auto [scaleX, scaleY] = scale;

        DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
        DxLib::DrawExtendGraph(x, y, x + static_cast<int>(texture.width * scaleX), y + static_cast<int>(texture.height * scaleY), texture.handle->texture, true);
    }
}

#endif
