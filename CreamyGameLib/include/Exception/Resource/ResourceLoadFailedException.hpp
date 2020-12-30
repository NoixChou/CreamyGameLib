#pragma once

#include "Exception/Exception.hpp"

namespace creamyLib::exception
{
    class ResourceLoadFailedException : public Exception
    {
    private:
        std::string fileName_;

    public:
        ResourceLoadFailedException(const std::string& resourceFileName = "", const std::string& message = "") : Exception(message), fileName_(resourceFileName) {}

        std::string getFileName() const
        {
            return fileName_;
        }
    };
}
