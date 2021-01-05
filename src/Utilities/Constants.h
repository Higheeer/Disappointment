//
// Created by Eryk on 22.10.2020.
//

#ifndef SIMPLERPG_SRC_CONSTANTS_H_
#define SIMPLERPG_SRC_CONSTANTS_H_

struct ChunkDimensions
{
	static float constexpr chunk_size{ 256 };
	static float constexpr block_size{ 32 };

	static int constexpr blocks_per_chunk{ static_cast<int>((chunk_size / block_size) * (chunk_size / block_size)) };
};

struct PlayerDimensions
{
	static float constexpr width{ 32 };
	static float constexpr height{ 32 };
	static std::pair<float, float> constexpr origin{ width / 2.f, height / 2.f };
};

struct WindowSize
{
	static unsigned int constexpr width{ 1280 };
	static unsigned int constexpr height{ 960 };
};

#endif //SIMPLERPG_SRC_CONSTANTS_H_
