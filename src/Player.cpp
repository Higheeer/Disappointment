//
// Created by Eryk on 20.10.2020.
//

#include "Player.h"

#include <numbers>
#include <cmath>

#include "Constants.h"
#include "Rifle.h"

using namespace SimpleRPG;

Player::Player(sf::Vector2f const& position, sf::Texture const& texture, sf::RenderWindow& window)
		: position{ position }, size{ PlayerDimensions::Width, PlayerDimensions::Height }, window{window}
{
	body.setPosition(this->position);
	body.setSize(size);
	body.setTexture(&texture);
	body.setOrigin(size.x / 2.f, size.y / 2.f);

	weapon = std::make_unique<Rifle>(window);
}

void Player::input(const float& deltaTime)
{
	move(deltaTime);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		weapon->shoot();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		weapon->reload();
	}
}

void Player::move(float const& deltaTime)
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

	position.x += velocity * direction.x * deltaTime;
	position.y += velocity * direction.y * deltaTime;
}

void Player::update(float const& deltaTime)
{
	rotation();
	weapon->update(deltaTime, position);
	body.setPosition(position.x, position.y);
}

void Player::rotation()
{
	sf::Vector2f mousePositionInWorld = window.mapPixelToCoords(sf::Mouse::getPosition(window));

	sf::Vector2f lookDirection = mousePositionInWorld - position;
	auto angle = static_cast<float>(std::atan2(lookDirection.y, lookDirection.x) * 180 / std::numbers::pi - 270);

	body.setRotation(angle);
}

sf::FloatRect Player::getBody() const
{
	return body.getGlobalBounds();
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*weapon, body.getTransform());
	target.draw(body);
}

float SimpleRPG::normalize(float value)
{
	return float(value * (value / (value * std::sqrt(2))));
}









