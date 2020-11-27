//
// Created by eryk on 19.11.2020.
//

#include "HUD.h"

#include <cmath>

#include "ChunkManager.h"
#include "Player.h"

HUD::HUD(sf::RenderWindow& window)
		: window(&window)
{
	this->font.loadFromFile("../res/fonts/hud.ttf");

	this->text.emplace(std::string("playerPosition"), sf::Text("X: 0 Y: 0", this->font, 36));
	this->text.emplace(std::string("amountOfChunks"), sf::Text("Amount of chunks: 0", this->font, 36));
}

void HUD::update(sf::Vector2f const& playerPosition, unsigned int const& amountOfChunks)
{
	/*  TODO: statyczny hud 0 x 0 + 25 x 25 tylko raz to obliczać bo tak to useless;*/
	auto convertedCoords = this->window->mapPixelToCoords({ 0, 0 });
	updatePlayerPosition(playerPosition, convertedCoords);
	updateAmountOfChunks(amountOfChunks, { convertedCoords.x, convertedCoords.y + 36 });
}

void HUD::updatePlayerPosition(sf::Vector2f const& playerPosition, sf::Vector2f const& textPosition)
{
	this->text.at("playerPosition").setString(
			"X: " + std::to_string(std::lround(playerPosition.x)) + " " +
			"Y: " + std::to_string(std::lround(playerPosition.y)));
	this->text.at("playerPosition").setPosition(textPosition.x, textPosition.y);
}

void HUD::updateAmountOfChunks(unsigned int const& amountOfChunks, sf::Vector2f const& textPosition)
{
	this->text.at("amountOfChunks").setString("Amount of chunks: " + std::to_string(amountOfChunks));
	this->text.at("amountOfChunks").setPosition(textPosition);
}

void HUD::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto const& i : text)
	{
		target.draw(i.second);
	}
}



