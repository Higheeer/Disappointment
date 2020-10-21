//
// Created by Eryk on 21.10.2020.
//

#include "Chunk.h"

Chunk::Chunk(sf::Vector2f const& position)
{

}

void Chunk::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for(auto& i : this->blocks)
	{
		target.draw(i, states);
	}
}

