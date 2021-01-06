//
// Created by Eryk on 28.12.2020.
//

#include <iostream>
#include <numbers>
#include "Enemy.h"

#include "Player.h"
#include "Utilities/RandomNumberGenerator.h"

using namespace Disappointment;

Enemy::Enemy(sf::Vector2f const& position, sf::Texture& texture)
		: strength{ 10 }, health{ 100 }, speed{ 50 }, attack_cooldown{ 2.f }, cooldown_timer{ 0 },
		  is_on_cooldown{ false }, field_of_view_offset{ 256 }
{
	body.setSize({ 32.f, 32.f });
	body.setPosition(position);
	body.setTexture(&texture);
	body.setRotation(RandomNumberGenerator::getNumber(0, 360));
	body.setOrigin(bodyBounds().width / 2, bodyBounds().height / 2);
}

void Enemy::update(float delta_time, Player& player)
{
	attack(player);
	cooldownTimer(delta_time);
	playerDetection(player, delta_time);
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

void Enemy::cooldownTimer(float delta_time)
{
	if (is_on_cooldown)
	{
		cooldown_timer += delta_time;
		if (cooldown_timer >= attack_cooldown)
		{
			is_on_cooldown = false;
		}
	}
}

void Enemy::playerDetection(Player& player, float delta_time)
{
	if (isInFieldOfView(player))
	{
		latest_known_position = sf::Vector2f{ player.bodyBounds().left, player.bodyBounds().top };
		rotateToLatestKnownPosition();

	}
	moveToLatestKnownPosition(delta_time);
}

bool Enemy::isInFieldOfView(const Player& player) const
{
	sf::FloatRect field_of_view;
	field_of_view = bodyBounds();
	field_of_view.left -= field_of_view_offset;
	field_of_view.top -= field_of_view_offset;
	field_of_view.height += field_of_view_offset * 2;
	field_of_view.width += field_of_view_offset * 2;

	return field_of_view.intersects(player.bodyBounds());
}

void Enemy::rotateToLatestKnownPosition()
{
	sf::Vector2f direction = latest_known_position.value() - body.getPosition();
	auto angle = static_cast<float>(std::atan2(direction.y, direction.x) * 180 / std::numbers::pi - 270);
	body.setRotation(angle);
}

void Enemy::moveToLatestKnownPosition(float delta_time)
{
	if (latest_known_position.has_value())
	{
		if (bodyBounds().contains(latest_known_position->x, latest_known_position->y))
		{
			latest_known_position.reset();
			return;
		}

		sf::Vector2f direction = latest_known_position.value() - body.getPosition();
		sf::Vector2f normalizedDirection =
				direction / static_cast<float>(sqrt(pow(direction.x, 2) + pow(direction.y, 2)));

		body.move(normalizedDirection * delta_time * speed);
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
	return health < 0;
}

void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(body);

}


