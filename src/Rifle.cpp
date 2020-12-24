//
// Created by Eryk on 23.12.2020.
//

#include "Rifle.h"

#include <utility>
#include <iostream>

Rifle::Rifle(std::string name)
		: name(std::move(name))
{
	body.setSize({ 6.f, 16.f });
	body.setOrigin({ 3.f, 4.f });
	body.move({ 28.0f, 0 });
}

void Rifle::reload()
{
	bulletsInMagazine = magazineSize;
}

void Rifle::update(float const& deltaTime, sf::Vector2f const& position, sf::RenderWindow const& window)
{

}

void Rifle::shoot()
{
	if(bulletsInMagazine > 0)
	{

		--bulletsInMagazine;
	}
}

void Rifle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(body, states);

}
