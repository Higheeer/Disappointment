//
// Created by Eryk on 03.11.2020.
//

#include "RandomNumberGenerator.h"

using namespace SimpleRPG;

std::random_device RandomNumberGenerator::seedGenerator{};
std::mt19937_64 RandomNumberGenerator::engine{ RandomNumberGenerator::seedGenerator() };

unsigned int RandomNumberGenerator::getNumber(unsigned int const& min, unsigned int const& max)
{
	std::uniform_int_distribution distribution(min, max);
	return distribution(engine);
}

void RandomNumberGenerator::setSeed(unsigned int const& seed)
{
	engine.seed(seed);
}
