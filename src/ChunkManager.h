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

	class ChunkManager : public sf::Drawable
	{
	public:
		explicit ChunkManager();

		void generateChunks(sf::Vector2f const& position);

		[[nodiscard]] Chunk getChunk(Index const& index) const;

		[[nodiscard]] unsigned int amountOfChunks() const;

	private:
		void createChunk(Index const& index);

		[[nodiscard]] bool hasNeighbours(Index const& index) const;

		void createNeighbours(Index const& index);

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		std::map<std::pair<int, int>, Chunk> chunks;
		int const chunkCreationRadius;
	};

	[[nodiscard]] Index coordsToIndex(float const& x, float const& y);

	[[nodiscard]] Index coordsToIndex(sf::Vector2f const& coords);

	[[nodiscard]] sf::Vector2f indexToCoords(Index const& index);
}


#endif //SIMPLERPG_CHUNKMANAGER_H
