#include "Randomizer.hpp"

float Randomizer::Random()
{
    return dist(gen);
}