#ifdef CREAMY_USE_DXLIB

#include "Render.hpp"

#include "../../../CreamyGameLib/include/Util/Color.hpp"

#include "DxLib.h"

namespace creamyLib::impl
{
    void RenderService::clearBuffer(const LibHandlePointer& libHandle, const Color& color)
    {
        const auto [r, g, b, a] = color;
        DxLib::SetBackgroundColor(r, g, b, a);
        DxLib::ClearDrawScreen();
        DxLib::clsDx();
    }

    void RenderService::presentBuffer(const LibHandlePointer& libHandle)
    {
        DxLib::ScreenFlip();
    }
}

#endif
