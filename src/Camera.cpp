//
// Created by Eryk on 22.10.2020.
//

#include <iostream>
#include "Camera.h"

#include "Terrain.h"
#include "Player.h"

Camera::Camera(Player& player)
	: player(&player)
{
	this->view.setSize(WindowSize::Width, WindowSize::Height);

	this->viewDistance = 3;

	this->playerOrigin.x = PlayerDimensions::Width / 2.0f;
	this->playerOrigin.y = PlayerDimensions::Height / 2.0f;
}

void Camera::update(Terrain const& terrain, sf::RenderWindow& window)
{
	this->visibleChunks.clear();

	checkVisibleChunks(terrain);

	this->view.setCenter({ this->player->getPosition() });
	window.setView(this->view);
}

void Camera::checkVisibleChunks(Terrain const& terrain)
{
	Index playerChunk{ Terrain::coordsToIndex(this->player->getPosition()) };
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
	clampViewSize();
}

void Camera::zoomOut()
{
	this->view.zoom(0.75);
	clampViewSize();
}

void Camera::draw(sf::RenderTarget& target, sf::RenderStates) const
{
	for (auto const& i : this->visibleChunks)
	{
		target.draw(i);
	}
}

void Camera::clampViewSize()
{
	sf::Vector2f viewSize = this->view.getSize();
	this->view.setSize(std::clamp(viewSize.x, ViewSize::Min, ViewSize::Max),
		std::clamp(viewSize.y, ViewSize::Min, ViewSize::Max));
}