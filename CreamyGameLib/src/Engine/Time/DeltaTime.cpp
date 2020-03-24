#include "Engine/Time/DeltaTime.hpp"

#include <chrono>

namespace creamyLib::engine
{
    std::chrono::high_resolution_clock::time_point DeltaTime::clockCount;
    float DeltaTime::deltaTime = 0.f;

    void DeltaTime::Update()
    {
        deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - clockCount).count() / 1000000.0f;
        clockCount = std::chrono::high_resolution_clock::now();
    }

    float DeltaTime::Get()
    {
        return deltaTime;
    }
}
