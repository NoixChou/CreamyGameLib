#pragma once

#include <string>
#include <utility>

namespace creamyLib
{
    struct Message
    {
        Message(std::string description) : description(std::move(description)) {}

        std::string description;
    };
}
