#pragma once

#include <exception>

namespace creamyLib::exception
{
    class Exception : public std::exception
    {
    public:
        Exception(const std::string& message) : std::exception(message.c_str()) {}
    };
}
