//
// Created by Eryk on 20.10.2020.
//

#include "Keyboard.h"

#include <SFML/Window/Keyboard.hpp>

#include "Player.h"

struct Direction
{
	int x: 2;
	int y: 2;
};

void Keyboard::playerMovementControl(Player& player, float const& deltaTime)
{
	Direction direction{ 0, 0 };
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		direction.y = -1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		direction.y = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		direction.x = -1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		direction.x = 1;
	}

	float velocity{ (direction.x != 0 && direction.y != 0) ? //Checks if player moves diagonally
					(250.f * 0.714f) : (250.f) };

	player.move({ velocity * direction.x * deltaTime, velocity * direction.y * deltaTime });
}
