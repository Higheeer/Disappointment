//
// Created by Eryk on 20.10.2020.
//

#include "Player.h"

#include <numbers>
#include <cmath>

#include "Utilities/Constants.h"

#include "Enemy.h"
#include "Weapons/Rifle.h"

using namespace Disappointment;

Player::Player(sf::Vector2f const& position, sf::Texture const& texture, sf::RenderWindow& window)
		: max_health{ 250 }, health{ max_health }, window{ window }
{
	body.setPosition(position);
	body.setSize({ PlayerDimensions::width, PlayerDimensions::height });
	body.setTexture(&texture);
	body.setOrigin({ PlayerDimensions::origin.first, PlayerDimensions::origin.second });

	weapon = std::make_unique<Rifle>(window);
}

void Player::input(float delta_time)
{
	move(delta_time);

	if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		weapon->shoot(body.getPosition());
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		weapon->reload();
	}
}

void Player::move(float delta_time)
{
	sf::Vector2f direction{};

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		direction.y = -1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		direction.y = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		direction.x = -1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		direction.x = 1;
	}

	float velocity{ 200.f };
	if (direction.x != 0 && direction.y != 0)
	{
		velocity = normalize(velocity);
	}

	sf::Vector2f move_offset;
	move_offset.x += velocity * direction.x * delta_time;
	move_offset.y += velocity * direction.y * delta_time;

	body.move(move_offset);
}

void Player::update(float delta_time, std::vector<Enemy>& enemy)
{
	rotateToMouse();
	weapon->update(delta_time, enemy);
}

void Player::rotateToMouse()
{
	sf::Vector2f mousePositionInWorld = window.mapPixelToCoords(sf::Mouse::getPosition(window));

	sf::Vector2f lookDirection = mousePositionInWorld - body.getPosition();
	auto angle = static_cast<float>(std::atan2(lookDirection.y, lookDirection.x) * 180 / std::numbers::pi - 270);

	body.setRotation(angle);
}

sf::FloatRect Player::bodyBounds() const
{
	return body.getGlobalBounds();
}

void Player::event(sf::Event const& event)
{

}

std::string Player::healthInPrecentage() const
{
	return std::to_string(health * 100 / max_health) + '%';
}

void Player::hit(unsigned short int value)
{
	health -= value;
}

bool Player::isDead() const
{
	return health < 0;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(body);
	target.draw(*weapon,body.getTransform());
}

float Disappointment::normalize(float value)
{
	return float(value * (value / (value * std::sqrt(2))));
}









