#pragma once
#include "SDLHandle.hpp"

namespace creamyLib::impl
{
    void ClearBuffer(const SDLHandlePointer sdlHandle);
    void PresentBuffer(const SDLHandlePointer sdlHandle);
}
