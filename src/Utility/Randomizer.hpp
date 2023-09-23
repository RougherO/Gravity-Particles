#pragma once
#include <random>

class Randomizer {
    inline static std::default_random_engine gen {};
    inline static std::uniform_real_distribution<float> dist { 0.f, 1.f };

public:
    static float Random();
};