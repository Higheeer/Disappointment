//
// Created by Eryk on 21.10.2020.
//

#ifndef SIMPLERPG_CHUNK_H
#define SIMPLERPG_CHUNK_H

#include <array>

#include <SFML/System/Vector2.hpp>

#include "Constants.h"

namespace Terrain
{
	class Chunk
	{
	public:
		explicit Chunk(sf::Vector2f const& position);

		enum class BlockType
		{
			Dirt, Stone, Sand
		};

	private:
		sf::Vector2f position;
		std::array<std::pair<BlockType, sf::Vector2f>, ChunkDimensions::BlocksPerChunk> blocks;
	};
}
#endif //SIMPLERPG_CHUNK_H
