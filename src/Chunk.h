//
// Created by Eryk on 21.10.2020.
//

#ifndef SIMPLERPG_CHUNK_H
#define SIMPLERPG_CHUNK_H

#include <SFML/Graphics.hpp>

#include <array>

#include "Constants.h"

class ChunkManager;

class Chunk : public sf::Drawable
{
 public:
	Chunk(sf::Vector2f const& position, Terrain& terrain);

 private:
	void createStructure();

	void createHouse();

	[[noreturn]] void draw(sf::RenderTarget& target, sf::RenderStates) const override;

 private:
	sf::Vector2f position;
	std::array<sf::RectangleShape, ChunkDimensions::BlocksPerChunk> blocks;

	ChunkManager* chunkManager;
};

#endif //SIMPLERPG_CHUNK_H
