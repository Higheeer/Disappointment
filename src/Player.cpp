//
// Created by Eryk on 20.10.2020.
//

#include "Player.h"

#include <numbers>
#include <cmath>

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

#include "Constants.h"


Player::Player(sf::Vector2f const& position, sf::Texture const& texture)
		: position{ position }, size{ PlayerDimensions::Width, PlayerDimensions::Height }
{
	this->body.setPosition(this->position);
	this->body.setSize(this->size);
	this->body.setTexture(&texture);
	this->body.setOrigin(PlayerDimensions::Width / 2.f, PlayerDimensions::Height / 2.f);
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

	float velocity{ 100.f };
	if (direction.x != 0 && direction.y != 0)
	{
		velocity = static_cast<float>((velocity * (velocity / (velocity * std::sqrt(2)))));
	}

	this->position.x += velocity * direction.x * deltaTime;
	this->position.y += velocity * direction.y * deltaTime;
}

void Player::rotation(sf::RenderWindow const& window)
{
	sf::Vector2f mousePositionInWorld = window.mapPixelToCoords(sf::Mouse::getPosition(window));

	sf::Vector2f lookDirection = mousePositionInWorld - this->position;
	auto angle = static_cast<float>(std::atan2(lookDirection.y, lookDirection.x) * 180 / std::numbers::pi - 270);

	this->body.setRotation(angle);
}

void Player::update(float const& deltaTime, sf::RenderWindow const& window)
{
	move(deltaTime);
	rotation(window);
	this->body.setPosition(this->position.x, this->position.y);
}

void Player::draw(sf::RenderTarget& window) const
{
	window.draw(this->body);
}

sf::Vector2f Player::getPosition() const
{
	return this->position;
}





