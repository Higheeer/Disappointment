//
// Created by Eryk on 20.10.2020.
//

#ifndef SIMPLERPG_PLAYER_H
#define SIMPLERPG_PLAYER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

#include "Camera.h"

namespace SimpleRPG
{
	class Player
	{
	public:
		Player(sf::Vector2f const& position, sf::Texture const& texture);

		void input(sf::Event const& event, float const& deltaTime);

		void rotation(sf::RenderWindow const& window);

		sf::Vector2f getPosition() const;

		void update(float const& deltaTime, sf::RenderWindow& window);

		void draw(sf::RenderTarget& window) const;

	private:
		void move(float const& deltaTime);

		sf::Vector2f position;
		sf::Vector2f size;

		sf::RectangleShape body;
		sf::RectangleShape weapon;

		Camera camera;
	};
}
#endif //SIMPLERPG_PLAYER_H
