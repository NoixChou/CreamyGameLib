#pragma once

#include "EngineObjectConfig.hpp"
#include "Application/Application.hpp"

namespace creamyLib::engine::object
{
    class EngineObject
    {
    protected:
        EngineObjectConfig config;

    public:
        EngineObject(const EngineObjectConfig& config);
        virtual ~EngineObject() = default;

        [[nodiscard]] virtual Application* GetApplication() const = 0;
    };
}
