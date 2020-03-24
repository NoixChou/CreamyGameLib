#pragma once

#include <string>

namespace creamyLib
{
    struct Message
    {
        Message(const std::string& description) : description(description) {}

        std::string description;
    };
}
