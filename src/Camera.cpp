//
// Created by Eryk on 22.10.2020.
//

#include "Camera.h"

#include "Terrain.h"
#include "Player.h"

#include "Constants.h"

Camera::Camera(Player& player)
	: player(&player)
{
	this->view.setSize(MAX_VIEW_SIZE, MAX_VIEW_SIZE);

	this->viewDistance = 1;

	playerOrigin.x = 28.f / 2.f;
	playerOrigin.y = 48.f / 2.f;

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

	this->view.setCenter({ this->player->getPosition() + this->playerOrigin });
	window.setView(this->view);
}

void Camera::checkVisibleChunks(Terrain const& terrain)
{
	Index playerChunk{ coordsToIndex(player->getPosition()) };
	for (int x = playerChunk.x - this->viewDistance; x <= playerChunk.x + this->viewDistance; x++)
	{
		for (int y = playerChunk.y - this->viewDistance; y <= playerChunk.y + this->viewDistance; y++)
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
