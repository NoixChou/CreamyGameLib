#ifdef CREAMY_USE_DXLIB

#include "Event.hpp"

#include "DxLib.h"

namespace creamyLib::impl
{
    bool WindowEvent::isQuit = false;

    void WindowEvent::Process()
    {
        isQuit = DxLib::ProcessMessage() == -1;
    }

    bool WindowEvent::IsQuit()
    {
        return isQuit;
    }
}

#endif
