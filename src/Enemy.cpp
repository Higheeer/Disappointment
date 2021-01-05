//
// Created by Eryk on 28.12.2020.
//

#include "Enemy.h"

#include "Player.h"

using namespace SimpleRPG;

Enemy::Enemy(sf::Vector2f const& position)
		: strength{ 10 }, health{ 100 }, speed{ 2 }, attack_cooldown{ 2.f }, cooldown_timer{ 0 },
		  is_on_cooldown{ false }
{
	body.setSize({ 32.f, 32.f });
	body.setPosition(position);
}

void Enemy::update(float delta_time, Player& player)
{
	attack(player);

	if (is_on_cooldown)
	{
		cooldown_timer += delta_time;
		if (cooldown_timer >= attack_cooldown)
		{
			is_on_cooldown = false;
		}
	}
}

void Enemy::attack(Player& player)
{
	if (bodyBounds().intersects(player.bodyBounds()))
	{
		if (!is_on_cooldown)
		{
			player.hit(strength);

			is_on_cooldown = true;
			cooldown_timer = 0;
		}
	}
}

void Enemy::hit(unsigned short int value)
{
	health -= value;
}

sf::FloatRect Enemy::bodyBounds() const
{
	return body.getGlobalBounds();
}

bool Enemy::isDead() const
{
	return health > 0;
}

void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(body);
}


