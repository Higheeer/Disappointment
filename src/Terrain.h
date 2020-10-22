//
// Created by Eryk on 21.10.2020.
//

#ifndef SIMPLERPG_TERRAIN_H
#define SIMPLERPG_TERRAIN_H

#include <map>

#include "Chunk.h"

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
	explicit Terrain(int const& chunkCreationRadius);

	void generateTerrain(Player const& player);

	[[nodiscard]]
	Chunk getChunk(Index const& index) const;

 private:
	void createChunk(Index const& index);

	[[nodiscard]]
	bool hasNeighbours(Index const& index) const;

	void createNeighbours(Index const& index);

 private:
	std::map<std::pair<int, int>, Chunk> chunks;
	int const chunkCreationRadius;
};

[[nodiscard]]
Index coordsToIndex(float const& x, float const& y);

[[nodiscard]]
Index coordsToIndex(sf::Vector2f const& coords);

[[nodiscard]]
sf::Vector2f indexToCoords(Index const& index);

#endif //SIMPLERPG_TERRAIN_H
