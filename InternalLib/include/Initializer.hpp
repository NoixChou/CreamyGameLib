#pragma once

#include "Handle.hpp"

namespace creamyLib::impl
{
    struct LibConfig;
    LibHandlePointer Initialize(const LibConfig& libConfig);
}
