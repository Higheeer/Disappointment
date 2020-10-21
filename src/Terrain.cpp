//
// Created by Eryk on 21.10.2020.
//

#include "Terrain.h"

Terrain::Terrain()
{
	//@TODO Dodać w to miejsce jakiś loader świata lub generator.
}

bool Terrain::hasNeighbours(Index const& chunkIndex) const
{
	return this->chunks.contains(std::make_pair(chunkIndex.x - 1, chunkIndex.y)) &&
		this->chunks.contains(std::make_pair(chunkIndex.x + 1, chunkIndex.y)) &&
		this->chunks.contains(std::make_pair(chunkIndex.x, chunkIndex.y - 1)) &&
		this->chunks.contains(std::make_pair(chunkIndex.x, chunkIndex.y + 1));
}

void Terrain::createNeighbours(Index const& chunkIndex)
{
	createChunk({ chunkIndex.x - 1, chunkIndex.y });
	createChunk({ chunkIndex.x + 1, chunkIndex.y });
	createChunk({ chunkIndex.x, chunkIndex.y - 1 });
	createChunk({ chunkIndex.x, chunkIndex.y + 1 });

}

void Terrain::createChunk(Index const& chunkIndex)
{
	if (this->chunks.contains(std::make_pair(chunkIndex.x, chunkIndex.y)))
	{
		return;
	}

	sf::Vector2f position{ chunkIndex.x * 1024.f, chunkIndex.y * 1024.f };
	this->chunks.emplace(std::make_pair(chunkIndex.x, chunkIndex.y), Chunk{ position });
}

Chunk Terrain::getChunk(const Index& chunkIndex) const
{
	return this->chunks.at(std::make_pair(chunkIndex.x, chunkIndex.y));
}


