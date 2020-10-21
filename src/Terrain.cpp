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
	return chunks.contains(std::make_pair(chunkIndex.x - 1, chunkIndex.y)) &&
		chunks.contains(std::make_pair(chunkIndex.x + 1, chunkIndex.y)) &&
		chunks.contains(std::make_pair(chunkIndex.x, chunkIndex.y - 1)) &&
		chunks.contains(std::make_pair(chunkIndex.x, chunkIndex.y + 1));
}

void Terrain::createNeighbours(Index const& chunkIndex)
{
	createChunk({ chunkIndex.x - 1, chunkIndex.y });
	createChunk({ chunkIndex.x + 1, chunkIndex.y });
	createChunk({ chunkIndex.x, chunkIndex.y - 1 });
	createChunk({ chunkIndex.x, chunkIndex.y + 1 });

}
