//
// Created by Eryk on 25.12.2020.
//

#include "Bullet.h"

#include "../Enemy.h"

using namespace Disappointment;

Bullet::Bullet(sf::Vector2f const& position, sf::Vector2f const& move_direction, float angle)
		: move_direction{ move_direction }, existence_time{ 0.f }, destroyed{ false }
{
	setPosition({ position.x, position.y });
	setRotation(angle);
	setSize({ 4.f, 5.f });
	setFillColor(sf::Color::Red);
}

void Bullet::update(float delta_time, std::vector<Enemy>& enemies)
{
	existence_time += delta_time;
	move(move_direction);
	hitTheEnemy(enemies);
}

void Bullet::hitTheEnemy(std::vector<Enemy>& enemies)
{
	for (auto& i: enemies)
	{
		if (getGlobalBounds().intersects(i.bodyBounds()))
		{
			destroyed = true;
			i.hit(5);
			break;
		}
	}
}

bool Bullet::shouldBeDestroyed() const
{
	return existence_time >= 2.f || destroyed;
}
