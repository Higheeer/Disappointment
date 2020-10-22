//
// Created by Eryk on 21.10.2020.
//

#include "Chunk.h"

#include "Constants.h"

Chunk::Chunk(sf::Vector2f const& position)
	: position(position)
{
	unsigned int row{ 0 }, column{ 0 };
	int const blocksPerRow{ static_cast<int>(sqrt(BLOCKS_PER_CHUNK)) };

	for (int i = 0; i < BLOCKS_PER_CHUNK; ++i)
	{
		sf::RectangleShape temporaryBlock;
		temporaryBlock.setSize({ BLOCK_SIZE, BLOCK_SIZE });
		temporaryBlock.setFillColor(sf::Color::Yellow);
		temporaryBlock.setPosition(column * BLOCK_SIZE + this->position.x, row * BLOCK_SIZE + this->position.y);

		this->blocks.push_back(std::move(temporaryBlock));

		if (++column == blocksPerRow)
		{
			column = 0;
			++row;
		}
	}
}

void Chunk::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto const& i : this->blocks)
	{
		target.draw(i);
	}

	target.draw(border);
}

