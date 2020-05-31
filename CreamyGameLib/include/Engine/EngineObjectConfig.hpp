#pragma once

namespace creamyLib::engine::object
{
    class EngineObject;

    struct EngineObjectConfig
    {
        EngineObject* owner = nullptr;
        int priority = 50;
    };
}
