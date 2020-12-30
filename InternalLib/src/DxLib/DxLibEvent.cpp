#ifdef CREAMY_USE_DXLIB

#include "Event.hpp"

#include "DxLib.h"

namespace creamyLib::impl
{
    bool WindowEvent::isQuit_ = false;

    void WindowEvent::process()
    {
        isQuit_ = DxLib::ProcessMessage() == -1;
    }

    bool WindowEvent::isQuit()
    {
        return isQuit_;
    }
}

#endif
