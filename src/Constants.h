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

struct ViewSize
{
	static float constexpr Max{ 768 };
	static float constexpr Min{ 256 };
};

struct PlayerDimensions
{
	static float constexpr Width{ 28 };
	static float constexpr Height{ 48 };
};

#endif //SIMPLERPG_SRC_CONSTANTS_H_
