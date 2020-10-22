//
// Created by Eryk on 22.10.2020.
//

#include "Camera.h"

#include "Terrain.h"
#include "Player.h"

#include <iostream> //@TODO do wyjebania

Camera::Camera(Player& player)
	: player(&player)
{
	this->view.setSize(768, 768);

	this->viewDistance.x = 1;
	this->viewDistance.y = 1;

	sf::Vector2f playerOrigin; //@TODO też do wyjebania
	playerOrigin.x = 28 / 2;//@TODO też do wyjebania
	playerOrigin.y = 48 / 2;//@TODO też do wyjebania

	this->view.setCenter({ this->player->getPosition() + playerOrigin });
}

void Camera::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto const& i : this->visibleChunks)
	{
		target.draw(i);
	}
}

void Camera::update(Terrain const& terrain, sf::RenderWindow& window)
{
	this->visibleChunks.clear();

	checkVisibleChunks(terrain);
	sf::Vector2f playerOrigin{ 14, 24 };//@TODO też do wyjebania

	this->view.setCenter({ this->player->getPosition() + playerOrigin });
	window.setView(this->view);
}

void Camera::checkVisibleChunks(Terrain const& terrain)
{
	Index playerChunk{ coordsToIndex(player->getPosition()) };
	for (int x = playerChunk.x - this->viewDistance.x; x <= playerChunk.x + this->viewDistance.x; x++)
	{
		for (int y = playerChunk.y - this->viewDistance.y; y <= playerChunk.y + this->viewDistance.y; y++)
		{
			addVisibleChunk(terrain.getChunk({ x, y }));
		}
	}
}

void Camera::addVisibleChunk(Chunk const& chunk)
{
	this->visibleChunks.push_back(chunk);
}

void Camera::zoomIn()
{
	view.zoom(2);
}

void Camera::zoomOut()
{
	view.zoom(0.5);
}
