//
// Created by Eryk on 01.11.2020.
//
#include "Mouse.h"

#include "Player.h"

Mouse::Mouse(Player& player)
	: player{ &player }, isSetDestination{ false }, speed{ 100 }
{

}

[[noreturn]] void Mouse::update(float const& deltaTime)
{
	if (isSetDestination)
	{
		player->move({ direction.x * speed * deltaTime, direction.y * speed * deltaTime });
		if (playerReachedDestination())
		{
			isSetDestination = false;
		}
	}
}

void Mouse::leftClick(sf::RenderWindow& window)
{
	auto const mousePosOnScreen = sf::Mouse::getPosition(window);
	auto const mousePosInWorld = window.mapPixelToCoords(mousePosOnScreen);

	this->destination = mousePosInWorld;
	isSetDestination = true;

	auto const distance = calculateDistance(this->player->getPosition(), this->destination);
	auto const length = calculateLength(distance);
	direction = normalize(distance, length);
}

sf::Vector2f Mouse::calculateDistance(sf::Vector2f const& start, sf::Vector2f const& end)
{
	return { end.x - start.x, end.y - start.y };
}

float Mouse::calculateLength(sf::Vector2f const& distance)
{
	return sqrt(pow(distance.x, 2) + pow(distance.y, 2));
}

sf::Vector2f Mouse::normalize(sf::Vector2f const& vectorToNormalize, float const& length)
{
	return { vectorToNormalize.x / length, vectorToNormalize.y / length };
}

bool Mouse::playerReachedDestination() const
{
	return (player->getPosition().x < destination.x + 4.f && player->getPosition().x > destination.x - 4.f)
		&& (player->getPosition().y < destination.y + 4.f && player->getPosition().y > destination.y - 4.f);
}


