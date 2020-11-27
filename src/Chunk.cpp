//
// Created by Eryk on 21.10.2020.
//

#include "Chunk.h"

#include <SFML/Graphics/RenderTarget.hpp>

#include "RandomNumberGenerator.h"

using namespace Terrain;

Chunk::Chunk(sf::Vector2f const& position)
		: position{ position }
{
	unsigned int row{ 0 }, column{ 0 };
	unsigned int const blocksPerRow{ static_cast<unsigned int>(std::sqrt(ChunkDimensions::BlocksPerChunk)) };

	blocks.setPrimitiveType(sf::Quads);

	for (unsigned int i = 0; i < ChunkDimensions::BlocksPerChunk; ++i)
	{
		blocks.append({{ column * ChunkDimensions::BlockSize + this->position.x,
						 row * ChunkDimensions::BlockSize + this->position.y }, sf::Color::Green });
		blocks.append({{ column * ChunkDimensions::BlockSize + this->position.x + ChunkDimensions::BlockSize,
						 row * ChunkDimensions::BlockSize + this->position.y }, sf::Color::Green });
		blocks.append({{ column * ChunkDimensions::BlockSize + this->position.x + ChunkDimensions::BlockSize,
						 row * ChunkDimensions::BlockSize + this->position.y + ChunkDimensions::BlockSize }, sf::Color::Green });
		blocks.append({{ column * ChunkDimensions::BlockSize + this->position.x,
						 row * ChunkDimensions::BlockSize + this->position.y + ChunkDimensions::BlockSize}, sf::Color::Green });

		if (++column == blocksPerRow)
		{
			column = 0;
			++row;
		}
	}
}

void Chunk::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(blocks);
}




