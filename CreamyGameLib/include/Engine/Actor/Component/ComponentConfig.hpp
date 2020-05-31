#pragma once
#include "Engine/EngineObjectConfig.hpp"

namespace creamyLib::engine
{
    struct ComponentConfig : object::EngineObjectConfig
    {
        bool isInject = true;
    };
}
