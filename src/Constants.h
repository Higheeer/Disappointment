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
	static float constexpr Width{ 28 };
	static float constexpr Height{ 48 };
};

struct WindowSize
{
	static unsigned int constexpr Width{ 1024 };
	static unsigned int constexpr Height{ 960 };
};

struct ViewSize
{
	static float constexpr Max{ 1024 };
	static float constexpr Min{ 300 };
};

#endif //SIMPLERPG_SRC_CONSTANTS_H_
