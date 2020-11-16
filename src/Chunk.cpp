//
// Created by Eryk on 21.10.2020.
//

#include "Chunk.h"

#include "RandomNumberGenerator.h"

using namespace Terrain;

Chunk::Chunk(sf::Vector2f const& position)
		: position{ position }
{
	unsigned int row{ 0 }, column{ 0 };
	unsigned int const blocksPerRow{ static_cast<unsigned int>(std::sqrt(ChunkDimensions::BlocksPerChunk)) };

	for (auto& block : blocks)
	{
		block = std::make_pair(BlockType::Dirt,
				sf::Vector2f{ column * ChunkDimensions::BlockSize + this->position.x,
							  row * ChunkDimensions::BlockSize + this->position.y });

		if (++column == blocksPerRow)
		{
			column = 0;
			++row;
		}
	}
}



