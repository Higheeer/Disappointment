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
		: window{ window }, magazine_size{ 30 }, bullets_in_magazine{ magazine_size }
{
	body.setSize({ 6.f, 16.f });
	body.setOrigin({ 3.f, 4.f });
	body.move({ 18.f, 0.f });
}

void Rifle::update(float delta_time, std::vector<Enemy>& enemy)
{
	for (auto& i : active_bullets)
	{
		i.update(delta_time, enemy);
	}

	active_bullets.erase(std::remove_if(active_bullets.begin(), active_bullets.end(),
			[](Bullet const& b)
			{ return b.shouldBeDestroyed(); }), active_bullets.end());
}

void Rifle::shoot(float delta_time, sf::Vector2f const& playerPosition)
{
	if (bullets_in_magazine > 0)
	{
		sf::Vector2f direction = window.mapPixelToCoords(sf::Mouse::getPosition(window)) - playerPosition;
		sf::Vector2f normalizedDirection =
				direction / static_cast<float>(sqrt(pow(direction.x, 2) + pow(direction.y, 2)));
		auto angle = static_cast<float>(
				std::atan2(normalizedDirection.y, normalizedDirection.x) * 180 / std::numbers::pi - 270);

		active_bullets.emplace_back(playerPosition, normalizedDirection, angle);

		--bullets_in_magazine;
	}
}

void Rifle::reload()
{
	bullets_in_magazine = magazine_size;
}

unsigned short int Rifle::bulletsLeft() const
{
	return bullets_in_magazine;
}

unsigned short int Rifle::magazineSize() const
{
	return magazine_size;
}

void Rifle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

	for (auto const& i: active_bullets)
	{
		target.draw(i);
	}
	target.draw(body, states);
}
