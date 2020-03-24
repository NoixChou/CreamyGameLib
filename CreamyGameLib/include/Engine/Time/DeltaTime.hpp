#pragma once

#include <chrono>

namespace creamyLib::engine
{
    class DeltaTime
    {
    private:
        static std::chrono::high_resolution_clock::time_point clockCount;
        static float deltaTime;

    public:
        static void Update();
        static float Get();
    };
}
