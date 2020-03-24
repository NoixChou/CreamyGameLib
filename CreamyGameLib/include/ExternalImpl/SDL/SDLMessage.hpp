#pragma once

#include <optional>

#include "../../Util/Message/Message.hpp"
#include "SDLHandle.hpp"

namespace creamyLib::impl
{
    struct SDLMessage : Message
    {
        bool isSucceed = false;
        SDLHandlePointer sdlHandle = nullptr;

        SDLMessage(const std::string& description, bool isSucceed, SDLHandlePointer sdlHandle = nullptr) : Message(description), isSucceed(isSucceed), sdlHandle(sdlHandle) {}
    };
}
