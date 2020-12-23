//
// Created by Eryk on 23.12.2020.
//

#include "Rifle.h"

#include <SFML/Graphics/RenderTarget.hpp>

#include "RifleAmmo.h"

Rifle::Rifle(std::string const& name)
		: name(name)
{
	body.setSize({ 6.f, 16.f });
	body.setOrigin({ 3.f, 4.f });
	body.move({ 28.0f, 0 });

	activeBullets.push_back(std::make_unique<RifleAmmo>());
}

void Rifle::reload()
{

}

void Rifle::update(float const& deltaTime)
{

}

void Rifle::shoot()
{

}

void Rifle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(body, states);

	for(auto const& i : activeBullets)
	{
		target.draw(*i, states);
	}
}
