#ifdef CREAMY_USE_DXLIB

#include "Initializer.hpp"
#include "Finalizer.hpp"
#include "Config.hpp"

#include <iostream>

#include "DxLib.h"

namespace creamyLib::impl
{
    LibHandlePointer Initialize(const LibConfig& libConfig)
    {
        DxLib::ChangeWindowMode(true);
        DxLib::SetUseCharCodeFormat(DX_CHARCODEFORMAT_UTF8);
        DxLib::SetMainWindowText(libConfig.windowTitle.c_str());
        DxLib::SetAlwaysRunFlag(TRUE);
        DxLib::SetWaitVSyncFlag(FALSE);
        DxLib::SetFontUseAdjustSizeFlag(FALSE);
        DxLib::SetUseFPUPreserveFlag(TRUE);
        DxLib::SetGraphMode(libConfig.windowWidth, libConfig.windowHeight, 32);
        DxLib::SetChangeScreenModeGraphicsSystemResetFlag(FALSE);

        if (DxLib::DxLib_Init() != 0)
        {
            return nullptr;
        }

        std::cout << "DxLib initialized" << std::endl;

        return new LibHandle{};
    }
}

#endif
