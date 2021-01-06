//
// Created by Eryk on 25.12.2020.
//

#include "Bullet.h"

#include "../Enemy.h"

using namespace Disappointment;

Bullet::Bullet(sf::Vector2f const& position, sf::Vector2f const& direction, float angle)
		: direction{ direction }, life_time{ 0.f }, should_destroy{false}
{
	setPosition({ position.x, position.y });
	setRotation(angle);
	setSize({ 4.f, 5.f });
	setFillColor(sf::Color::Red);
}

void Bullet::update(float delta_time, std::vector<Enemy>& enemy)
{
	life_time += delta_time;
	move(direction);
	for(auto& i: enemy)
	{
		if(getGlobalBounds().intersects(i.bodyBounds()))
		{
			should_destroy = true;
			i.hit(5);
			break;
		}
	}
}

bool Bullet::shouldBeDestroyed() const
{
	return life_time >= 2.f || should_destroy;
}
