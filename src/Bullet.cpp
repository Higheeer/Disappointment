//
// Created by Eryk on 25.12.2020.
//

#include "Bullet.h"

Bullet::Bullet(sf::Vector2f const& position, sf::Vector2f const& direction, float angle)
		: direction{ direction }, lifeTime{ 0.f }
{
	setPosition({ position.x, position.y });
	setRotation(angle);
	setSize({ 4.f, 5.f });
	setFillColor(sf::Color::Red);
}

void Bullet::update(float deltaTime)
{
	lifeTime += deltaTime;
	move(direction);
}

bool Bullet::shouldBeDestroyed() const
{
	return lifeTime >= 0.5f;
}
