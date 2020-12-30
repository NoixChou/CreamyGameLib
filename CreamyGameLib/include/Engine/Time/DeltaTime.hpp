#pragma once

#include <chrono>

namespace creamyLib::engine
{
    class DeltaTime
    {
    private:
        static std::chrono::high_resolution_clock::time_point clockCount_;
        static float deltaTime_;

    public:
        static void init();
        static void update();
        static float get();
    };
}
