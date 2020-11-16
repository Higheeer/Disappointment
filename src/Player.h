//
// Created by Eryk on 20.10.2020.
//

#ifndef SIMPLERPG_PLAYER_H
#define SIMPLERPG_PLAYER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

class Player
{
 public:
	Player(sf::Vector2f const& position, sf::Texture const& texture);

	void move(float const& deltaTime);

	void rotation(sf::RenderWindow const& window);

	sf::Vector2f getPosition() const;

	void update(float const& deltaTime, sf::RenderWindow const& window);

	void draw(sf::RenderTarget& window) const;

 private:
	sf::Vector2f position;
	sf::Vector2f size;

	sf::RectangleShape body;
};

#endif //SIMPLERPG_PLAYER_H
