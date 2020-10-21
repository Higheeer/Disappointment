//
// Created by Eryk on 21.10.2020.
//

#ifndef SIMPLERPG_TERRAIN_H
#define SIMPLERPG_TERRAIN_H

#include <map>

#include "Chunk.h"

//@TODO: chunk size 64x64 i 16x16 block size

struct Index
{
	Index(int const& x, int const& y)
		: x{ x }, y{ y }
	{
	}

	int const x;
	int const y;
};

class Player;

class Terrain
{
 public:
	Terrain();

	void createChunk(Index const& chunkIndex);

	[[nodiscard]]
	Chunk getChunk(Index const& chunkIndex) const;

 private:
	[[nodiscard]]
	bool hasNeighbours(Index const& chunkIndex) const;

	void createNeighbours(Index const& chunkIndex);

 private:
	std::map<std::pair<int, int>, Chunk> chunks;
};

#endif //SIMPLERPG_TERRAIN_H
