//
// Created by Eryk on 23.12.2020.
//

#include "RifleAmmo.h"

RifleAmmo::RifleAmmo()
{
	setSize({4.f, 8});
	setOrigin({2.f, 8.f});
	setFillColor(sf::Color::Red);
	move(28, -4.f);
}

void RifleAmmo::update(float const& deltaTime)
{

}

void RifleAmmo::hit()
{

}
