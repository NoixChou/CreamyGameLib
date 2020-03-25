#ifdef CREAMY_USE_DXLIB

#include "Render.hpp"

#include "DxLib.h"

namespace creamyLib::impl
{
    void RenderService::ClearBuffer(const LibHandlePointer libHandle)
    {
        DxLib::ClearDrawScreen();
        DxLib::clsDx();
    }

    void RenderService::PresentBuffer(const LibHandlePointer libHandle)
    {
        DxLib::ScreenFlip();
    }
}

#endif
