//
// Created by Eryk on 21.10.2020.
//

#ifndef SIMPLERPG_CHUNK_H
#define SIMPLERPG_CHUNK_H

#include <array>

#include <SFML/Graphics.hpp>

class Chunk : public sf::Drawable
{
 public:
	explicit Chunk(sf::Vector2f const& position);

 private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

 private:
	sf::Vector2f position;
	std::array<sf::RectangleShape, 9> blocks;
};

#endif //SIMPLERPG_CHUNK_H
