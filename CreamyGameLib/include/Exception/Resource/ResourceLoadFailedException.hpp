#pragma once

#include "Exception/Exception.hpp"

namespace creamyLib::exception
{
    class ResourceLoadFailedException : public Exception
    {
    private:
        std::string fileName = "";

    public:
        ResourceLoadFailedException(const std::string& resourceFileName = "", const std::string& message = "") : Exception(message), fileName(resourceFileName) {}

        std::string GetFileName() const
        {
            return fileName;
        }
    };
}
