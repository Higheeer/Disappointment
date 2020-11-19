//
// Created by Eryk on 21.10.2020.
//

#include "ChunkManager.h"

#include <cmath>

#include "Player.h"

using namespace Terrain;

ChunkManager::ChunkManager()
		: chunkCreationRadius{ 5 }
{
	chunks.clear();
}

bool ChunkManager::hasNeighbours(Index const& index) const
{
	return this->chunks.contains(std::make_pair(index.x - 1, index.y)) &&
		   this->chunks.contains(std::make_pair(index.x + 1, index.y)) &&
		   this->chunks.contains(std::make_pair(index.x, index.y - 1)) &&
		   this->chunks.contains(std::make_pair(index.x, index.y + 1));
}

void ChunkManager::createNeighbours(Index const& index)
{
	createChunk({ index.x - 1, index.y });
	createChunk({ index.x + 1, index.y });
	createChunk({ index.x, index.y - 1 });
	createChunk({ index.x, index.y + 1 });
}

void ChunkManager::createChunk(Index const& index)
{
	if (this->chunks.contains(std::make_pair(index.x, index.y)))
	{
		return;
	}

	sf::Vector2f position = indexToCoords(index);
	this->chunks.emplace(std::make_pair(index.x, index.y), Chunk{ position });
}

Chunk ChunkManager::getChunk(const Index& index) const
{
	return this->chunks.at(std::make_pair(index.x, index.y));
}

void ChunkManager::generateChunks(sf::Vector2f const& position)
{
	Index const chunkId{ coordsToIndex(position) }; //TODO: Trzeba zmienic nazwe tej zmiennej 'chunkId' na coś innego

	for (int x = chunkId.x - this->chunkCreationRadius; x <= chunkId.x + this->chunkCreationRadius; ++x)
	{
		for (int y = chunkId.y - this->chunkCreationRadius; y <= chunkId.y + this->chunkCreationRadius; ++y)
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


