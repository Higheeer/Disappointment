//
// Created by Eryk on 21.10.2020.
//

#ifndef SIMPLERPG_CHUNKMANAGER_H
#define SIMPLERPG_CHUNKMANAGER_H

#include <map>

#include "Chunk.h"



class Player;

namespace Terrain
{
	struct Index
	{
		int const x;
		int const y;
	};

	class ChunkManager
	{
	public:
		ChunkManager();

		void generateTerrain(Player const& player);

		[[nodiscard]] Chunk getChunk(Index const& index) const;

		[[nodiscard]] static Index coordsToIndex(float const& x, float const& y);

		[[nodiscard]] static Index coordsToIndex(sf::Vector2f const& coords);

		[[nodiscard]] static sf::Vector2f indexToCoords(Index const& index);

	private:
		void createChunk(Index const& index);

		[[nodiscard]] bool hasNeighbours(Index const& index) const;

		void createNeighbours(Index const& index);

	private:
		std::map<std::pair<int, int>, Chunk> chunks;
		int const chunkCreationRadius;
	};
}


#endif //SIMPLERPG_CHUNKMANAGER_H
