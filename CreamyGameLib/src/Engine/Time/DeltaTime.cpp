#include "Engine/Time/DeltaTime.hpp"

#include <chrono>

namespace creamyLib::engine
{
    std::chrono::high_resolution_clock::time_point DeltaTime::clockCount_;
    float DeltaTime::deltaTime_ = 0.f;

    void DeltaTime::init()
    {
        clockCount_ = std::chrono::high_resolution_clock::now();
    }

    void DeltaTime::update()
    {
        deltaTime_ = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - clockCount_).count() / 1000000.0f;
        clockCount_ = std::chrono::high_resolution_clock::now();
    }

    float DeltaTime::get()
    {
        return deltaTime_;
    }
}
