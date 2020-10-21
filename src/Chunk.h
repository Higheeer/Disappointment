//
// Created by Eryk on 21.10.2020.
//

#ifndef SIMPLERPG_CHUNK_H
#define SIMPLERPG_CHUNK_H

#include <array>

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

class Chunk
{
 public:
	Chunk(sf::Vector2f const& position);

 private:
	sf::Vector2f position;
	std::array<sf::RectangleShape, 9> blocks;
};

#endif //SIMPLERPG_CHUNK_H
