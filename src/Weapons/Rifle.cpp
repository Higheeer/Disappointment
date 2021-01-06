//
// Created by Eryk on 23.12.2020.
//

#include "Rifle.h"

#include <iostream>
#include <numbers>
#include <algorithm>

#include <SFML/Window/Mouse.hpp>

#include "../Enemy.h"

using namespace Disappointment;

Rifle::Rifle(sf::RenderWindow& window)
		: window{ window }, magazineSize{ 100 }, bulletsInMagazine{ magazineSize }
{
	body.setSize({ 6.f, 16.f });
	body.setOrigin({ 3.f, 4.f });
	body.move({ 18.f, 0.f });
}

void Rifle::reload()
{
	bulletsInMagazine = magazineSize;
}

void Rifle::update(float delta_time, std::vector<Enemy>& enemy)
{
	for (auto& i : activeBullets)
	{
		i.update(delta_time, enemy);
	}

	activeBullets.erase(std::remove_if(activeBullets.begin(), activeBullets.end(),
			[](Bullet const& b)
			{ return b.shouldBeDestroyed(); }), activeBullets.end());
}

void Rifle::shoot(sf::Vector2f const& playerPosition)
{
	if (bulletsInMagazine > 0)
	{
		sf::Vector2f direction = window.mapPixelToCoords(sf::Mouse::getPosition(window)) - playerPosition;
		sf::Vector2f normalizedDirection =
				direction / static_cast<float>(sqrt(pow(direction.x, 2) + pow(direction.y, 2)));
		auto angle = static_cast<float>(
				std::atan2(normalizedDirection.y, normalizedDirection.x) * 180 / std::numbers::pi - 270);

		normalizedDirection.x *= 10;
		normalizedDirection.y *= 10;

		activeBullets.emplace_back(playerPosition, normalizedDirection, angle);

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
