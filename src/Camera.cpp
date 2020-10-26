//
// Created by Eryk on 22.10.2020.
//

#include "Camera.h"

#include "Terrain.h"
#include "Player.h"

Camera::Camera(Player& player)
	: player(&player), cameraSpeed(300.f), offset(50)
{
	this->view.setSize(WindowSize::Width, WindowSize::Height);

	this->viewDistance = 2;

	this->playerOrigin.x = PlayerDimensions::Width / 2.0f;
	this->playerOrigin.y = PlayerDimensions::Height / 2.0f;

	this->view.setCenter({ this->player->getPosition() + this->playerOrigin });
}

void Camera::update(Terrain const& terrain, sf::RenderWindow& window)
{
	this->visibleChunks.clear();

	checkVisibleChunks(terrain);

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

void Camera::draw(sf::RenderTarget& target, sf::RenderStates) const
{
	for (auto const& i : this->visibleChunks)
	{
		target.draw(i);
	}
}

//@TODO ten kod jest do poprawy, lub wywalenia
/*
void Camera::mouseControl(float const& deltaTime, sf::RenderWindow const& window)
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

	sf::Vector2f distanceToNearestScreenBorder{ 0, 0 };
	sf::Vector2f distanceRatioBetweenMouseAndBorder{ 0, 0 };

	if (mousePosition.x < offset)
	{
		distanceToNearestScreenBorder.x = static_cast<float>(offset - mousePosition.x);
		direction.x = -1;
	}
	if (mousePosition.x > WindowSize::Width - offset)
	{
		distanceToNearestScreenBorder.x = static_cast<float>( mousePosition.x - (WindowSize::Width - offset - 1));
		direction.x = 1;
	}
	if (mousePosition.y < offset)
	{
		distanceToNearestScreenBorder.y = static_cast<float>(offset - mousePosition.y);
		direction.y = -1;
	}
	if (mousePosition.y > WindowSize::Height - offset)
	{
		distanceToNearestScreenBorder.y = static_cast<float>( mousePosition.y - (WindowSize::Height - offset - 1));
		direction.y = 1;
	}

	distanceRatioBetweenMouseAndBorder.x = distanceToNearestScreenBorder.x / offset;
	distanceRatioBetweenMouseAndBorder.y = distanceToNearestScreenBorder.y / offset;

	float const normalizedCameraSpeed{ (direction.x != 0 && direction.y != 0) ?
									   (cameraSpeed * (cameraSpeed / (cameraSpeed * std::sqrt(2.f)))) : (cameraSpeed) };

	this->view.move({
		static_cast<float>(direction.x * (distanceRatioBetweenMouseAndBorder.x * normalizedCameraSpeed) * deltaTime),
		static_cast<float>(direction.y * (distanceRatioBetweenMouseAndBorder.y * normalizedCameraSpeed) * deltaTime) });

	this->view.setCenter(std::clamp(this->view.getCenter().x,
		this->player->getPosition().x - 250.f,
		this->player->getPosition().x + playerOrigin.x + 250.f), this->view.getCenter().y);

	this->view.setCenter(this->view.getCenter().x,
		std::clamp(this->view.getCenter().y,
			this->player->getPosition().y - 250.f,
			this->player->getPosition().y + playerOrigin.y + 250.f));


}*/