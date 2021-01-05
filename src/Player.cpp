//
// Created by Eryk on 20.10.2020.
//

#include "Player.h"

#include <numbers>
#include <cmath>

#include "Utilities/Constants.h"

using namespace SimpleRPG;

Player::Player(sf::Vector2f const& position, sf::Texture const& texture, sf::RenderWindow& window)
		: attribs{ 874, attribs.max_health }, window{ window }
{
	body.setPosition(position);
	body.setSize({ PlayerDimensions::width, PlayerDimensions::height });
	body.setTexture(&texture);
	body.setOrigin({ PlayerDimensions::origin.first, PlayerDimensions::origin.second });
}

void Player::input(float delta_time)
{
	move(delta_time);
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

void Player::update(float delta_time)
{
	rotation();
}

void Player::rotation()
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

std::string Player::health() const
{
	return std::to_string(attribs.health * 100 / attribs.max_health) + '%';
}

void Player::hit(unsigned short int value)
{
	attribs.health -= value;
}

bool Player::isDead() const
{
	return attribs.health < 0;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(body);
}

float SimpleRPG::normalize(float value)
{
	return float(value * (value / (value * std::sqrt(2))));
}









