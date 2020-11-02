//
// Created by Eryk on 21.10.2020.
//

#include "Terrain.h"

#include "Player.h"

Terrain::Terrain()
	: chunkCreationRadius{5}
{

}

bool Terrain::hasNeighbours(Index const& index) const
{
	return this->chunks.contains(std::make_pair(index.x - 1, index.y)) &&
		this->chunks.contains(std::make_pair(index.x + 1, index.y)) &&
		this->chunks.contains(std::make_pair(index.x, index.y - 1)) &&
		this->chunks.contains(std::make_pair(index.x, index.y + 1));
}

void Terrain::createNeighbours(Index const& index)
{
	createChunk({ index.x - 1, index.y });
	createChunk({ index.x + 1, index.y });
	createChunk({ index.x, index.y - 1 });
	createChunk({ index.x, index.y + 1 });
}

void Terrain::createChunk(Index const& index)
{
	if (this->chunks.contains(std::make_pair(index.x, index.y)))
	{
		return;
	}

	sf::Vector2f position = indexToCoords(index);
	this->chunks.emplace(std::make_pair(index.x, index.y), Chunk{ position });
}

Chunk Terrain::getChunk(const Index& index) const
{
	return this->chunks.at(std::make_pair(index.x, index.y));
}

void Terrain::generateTerrain(Player const& player)
{
	Index const playerChunk{ coordsToIndex(player.getPosition()) };

	for (int x = playerChunk.x - this->chunkCreationRadius; x <= playerChunk.x + this->chunkCreationRadius; ++x)
	{
		for (int y = playerChunk.y - this->chunkCreationRadius; y <= playerChunk.y + this->chunkCreationRadius; ++y)
		{
			createChunk({ x, y });
			if (!hasNeighbours({ x, y }))
			{
				createNeighbours({ x, y });
			}
		}
	}
}

Index Terrain::coordsToIndex(float const& x, float const& y)
{
	return { static_cast<int>(std::floor(x / ChunkDimensions::ChunkSize)),
			 static_cast<int>(std::floor(y / ChunkDimensions::ChunkSize)) };
}

Index Terrain::coordsToIndex(sf::Vector2f const& coords)
{
	return { static_cast<int>(std::floor(coords.x / ChunkDimensions::ChunkSize)),
			 static_cast<int>(std::floor(coords.y / ChunkDimensions::ChunkSize)) };
}

sf::Vector2f Terrain::indexToCoords(Index const& index)
{
	return { static_cast<float>(index.x * ChunkDimensions::ChunkSize),
			 static_cast<float>(index.y * ChunkDimensions::ChunkSize) };
}


