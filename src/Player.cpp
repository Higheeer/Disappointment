//
// Created by Eryk on 20.10.2020.
//

#include "Player.h"

#include <numbers>
#include <cmath>
#include <iostream>

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

#include "Constants.h"
#include "Rifle.h"

using namespace SimpleRPG;

Player::Player(sf::Vector2f const& position, sf::Texture const& texture)
		: position{ position }, size{ PlayerDimensions::Width, PlayerDimensions::Height }
{
	body.setPosition(this->position);
	body.setSize(size);
	body.setTexture(&texture);
	body.setOrigin(size.x / 2.f, size.y / 2.f);

	weapon = std::make_unique<Rifle>("Ak-47");
}

void Player::input(const float& deltaTime)
{
	move(deltaTime);
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

	position.x += velocity * direction.x * deltaTime;
	position.y += velocity * direction.y * deltaTime;
}

void Player::rotation(sf::RenderWindow const& window)
{
	sf::Vector2f mousePositionInWorld = window.mapPixelToCoords(sf::Mouse::getPosition(window));

	sf::Vector2f lookDirection = mousePositionInWorld - position;
	auto angle = static_cast<float>(std::atan2(lookDirection.y, lookDirection.x) * 180 / std::numbers::pi - 270);

	body.setRotation(angle);
}

void Player::update(float const& deltaTime, sf::RenderWindow& window)
{
	move(deltaTime);
	rotation(window);
	body.setPosition(position.x, position.y);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(body);
	target.draw(*weapon, body.getTransform());
}









