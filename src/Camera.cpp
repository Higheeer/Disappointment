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
	this->view.setSize(ViewSize::Max, ViewSize::Max);

	this->viewDistance = 1;

	this->playerOrigin.x = PlayerDimensions::Width / 2.0f;
	this->playerOrigin.y = PlayerDimensions::Height / 2.0f;

	this->view.setCenter({ this->player->getPosition() + this->playerOrigin });
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
	this->view.zoom(1.25);

	sf::Vector2f viewSize = this->view.getSize();
	view.setSize(std::clamp(viewSize.x, ViewSize::Min, ViewSize::Max),
		std::clamp(viewSize.y, ViewSize::Min, ViewSize::Max));
}

void Camera::zoomOut()
{
	this->view.zoom(0.75);

	sf::Vector2f viewSize = this->view.getSize();
	this->view.setSize(std::clamp(viewSize.x, ViewSize::Min, ViewSize::Max),
		std::clamp(viewSize.y, ViewSize::Min, ViewSize::Max));
}

void Camera::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto const& i : this->visibleChunks)
	{
		target.draw(i, states);
	}
}
