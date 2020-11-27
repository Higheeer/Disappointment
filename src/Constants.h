//
// Created by Eryk on 22.10.2020.
//

#ifndef SIMPLERPG_SRC_CONSTANTS_H_
#define SIMPLERPG_SRC_CONSTANTS_H_

struct ChunkDimensions
{
	static float constexpr ChunkSize{ 256 };
	static float constexpr BlockSize{ 32 };

	static int constexpr BlocksPerChunk{ static_cast<int>((ChunkSize / BlockSize) * (ChunkSize / BlockSize)) };
};

struct PlayerDimensions
{
	static float constexpr Width{ 32 };
	static float constexpr Height{ 32 };
};

struct WindowSize
{
	static unsigned int constexpr Width{ 1280 };
	static unsigned int constexpr Height{ 960 };
};

#endif //SIMPLERPG_SRC_CONSTANTS_H_
