//
// Created by Eryk on 21.10.2020.
//

#include "Chunk.h"

#include "Constants.h"

Chunk::Chunk(sf::Vector2f const& position)
	: position(position)
{
	unsigned int row{ 0 }, column{ 0 };
	unsigned int const blocksPerRow{ static_cast<unsigned int>(sqrt(ChunkDimensions::BlocksPerChunk)) };

	for (int i = 0; i < ChunkDimensions::BlocksPerChunk; ++i)
	{
		sf::RectangleShape temporaryBlock;
		temporaryBlock.setSize({ ChunkDimensions::BlockSize, ChunkDimensions::BlockSize });
		temporaryBlock.setFillColor(sf::Color::Yellow);
		temporaryBlock.setPosition(column * ChunkDimensions::BlockSize + this->position.x,
			row * ChunkDimensions::BlockSize + this->position.y);

		this->blocks.push_back(std::move(temporaryBlock));

		if (++column == blocksPerRow)
		{
			column = 0;
			++row;
		}
	}
}

void Chunk::draw(sf::RenderTarget& target, sf::RenderStates) const
{
	for (auto const& i : this->blocks)
	{
		target.draw(i);
	}

	target.draw(border);
}

