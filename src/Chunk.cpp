//
// Created by Eryk on 21.10.2020.
//

#include "Chunk.h"

#include "ChunkManager.h"

#include "RandomNumberGenerator.h"

Chunk::Chunk(sf::Vector2f const& position, Terrain& terrain)
	: position{ position }, terrain{ &terrain }
{
	unsigned int row{ 0 }, column{ 0 };
	unsigned int const blocksPerRow{ static_cast<unsigned int>(sqrt(ChunkDimensions::BlocksPerChunk)) };

	for (int i = 0; i < ChunkDimensions::BlocksPerChunk; ++i)
	{
		sf::RectangleShape temporaryBlock;
		temporaryBlock.setSize({ ChunkDimensions::BlockSize, ChunkDimensions::BlockSize });
		temporaryBlock.setFillColor(sf::Color(0, 128, 0));
		temporaryBlock.setPosition(column * ChunkDimensions::BlockSize + this->position.x,
			row * ChunkDimensions::BlockSize + this->position.y);

		this->blocks[i] = std::move(temporaryBlock);

		if (++column == blocksPerRow)
		{
			column = 0;
			++row;
		}
	}

	createStructure();
}

[[noreturn]] void Chunk::draw(sf::RenderTarget& target, sf::RenderStates) const
{
	for (auto const& i : this->blocks)
	{
		target.draw(i);
	}
}

void Chunk::createStructure()
{
	switch (RandomNumberGenerator::getNumber(0, 50))
	{
		case 1:
		{
			createHouse();
			break;
		}
	}
}

void Chunk::createHouse()
{
	this->blocks[4].setFillColor(sf::Color(128, 12, 255));
}

