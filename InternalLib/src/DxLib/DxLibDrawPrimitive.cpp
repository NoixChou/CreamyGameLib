#ifdef CREAMY_USE_DXLIB

#include "DrawPrimitive.hpp"

#include "../../../CreamyGameLib/include/Util/Color.hpp"
#include "../../../CreamyGameLib/include/Math/Vector2.hpp"

#include "DxLib.h"

namespace creamyLib::impl
{
    void DrawRect(const LibHandlePointer& libHandle, const math::Vector2& position, const math::Vector2& size, const Color& color, bool isFill)
    {
        const auto [r, g, b, a] = color;
        const auto [x, y] = position;
        const auto [width, height] = size;

        int l_CurrentBlendMode, l_CurrentBlendParam;
        DxLib::GetDrawBlendMode(&l_CurrentBlendMode, &l_CurrentBlendParam);
        DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, a);
        DxLib::DrawBox(x, y, x + width, y + height, DxLib::GetColor(r, g, b), isFill);
        DxLib::SetDrawBlendMode(l_CurrentBlendMode, l_CurrentBlendParam);
    }
}

#endif
