//
// Created by Eryk on 03.11.2020.
//

#ifndef SIMPLERPG_SRC_RANDOMNUMBERGENERATOR_H_
#define SIMPLERPG_SRC_RANDOMNUMBERGENERATOR_H_

#include <random>

class RandomNumberGenerator
{
 public:
	RandomNumberGenerator() = delete;

 private:
	static std::random_device seedGenerator;
	static std::mt19937_64 engine;

	static unsigned int getNumber(unsigned int const& min, unsigned int const& max);

	static void setSeed(unsigned int const& seed);
};

#endif //SIMPLERPG_SRC_RANDOMNUMBERGENERATOR_H_
