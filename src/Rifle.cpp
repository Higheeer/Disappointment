//
// Created by Eryk on 23.12.2020.
//

#include "Rifle.h"

#include <iostream>
#include <numbers>
#include <algorithm>

#include <SFML/Window/Mouse.hpp>

Rifle::Rifle(sf::RenderWindow& window)
		: window{ window }, magazineSize{ 10000 }, bulletsInMagazine{ magazineSize }
{
	body.setSize({ 6.f, 16.f });
	body.setOrigin({ 3.f, 4.f });
	body.move({ 18.f, 0.f });
}

void Rifle::reload()
{
	bulletsInMagazine = magazineSize;
}

void Rifle::update(float const& deltaTime, sf::Vector2f const& playerPosition)
{
	position = playerPosition;

	for (auto& i : activeBullets)
	{
		i.update(deltaTime);
	}

	activeBullets.erase(std::remove_if(activeBullets.begin(), activeBullets.end(),
			[](Bullet b)
			{ return b.shouldBeDestroyed(); }), activeBullets.end());
}

void Rifle::shoot()
{
	if (bulletsInMagazine > 0)
	{
		sf::Vector2f direction = window.mapPixelToCoords(sf::Mouse::getPosition(window)) - position;
		sf::Vector2f normalizedDirection =
				direction / static_cast<float>(sqrt(pow(direction.x, 2) + pow(direction.y, 2)));
		auto angle = static_cast<float>(
				std::atan2(normalizedDirection.y, normalizedDirection.x) * 180 / std::numbers::pi - 270);

		normalizedDirection.x *= 20;
		normalizedDirection.y *= 20;

		activeBullets.emplace_back(position, normalizedDirection, angle);

		--bulletsInMagazine;
	}
}

void Rifle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

	for (auto const& i: activeBullets)
	{
		target.draw(i);
	}
	target.draw(body, states);
}
