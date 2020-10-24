//
// Created by Eryk on 20.10.2020.
//

#include "Player.h"

#include "Constants.h"

Player::Player(sf::Vector2f const& position, sf::Texture const& texture)
	: position{ position }, size{ PlayerDimensions::Width, PlayerDimensions::Height }
{
	this->body.setPosition(this->position);
	this->body.setSize(this->size);
	this->body.setTexture(&texture);
}

void Player::move(sf::Vector2f const& offset)
{
	this->position += offset;
}

void Player::update(/*float const& deltaTime*/)
{

	this->body.setPosition(this->position);
}

void Player::draw(sf::RenderTarget& window) const
{
	window.draw(this->body);
}

sf::Vector2f Player::getPosition() const
{
	return this->position;
}


