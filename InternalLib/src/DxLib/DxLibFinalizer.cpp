#ifdef CREAMY_USE_DXLIB

#include "Finalizer.hpp"

#include "DxLib.h"

namespace creamyLib::impl
{
    void Finalize(const LibHandlePointer libHandle)
    {
        if(!libHandle)
        {
            return;
        }

        DxLib::DxLib_End();

        delete libHandle;
    }
}

#endif
