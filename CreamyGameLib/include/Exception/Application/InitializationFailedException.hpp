#pragma once

#include "Exception/Exception.hpp"

namespace creamyLib::exception
{
    class InitializationFailedException : public Exception
    {
    public:
        InitializationFailedException(const std::string& message) : Exception(message) {}
    };
}
