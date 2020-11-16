//
// Created by Eryk on 22.10.2020.
//

#include "Camera.h"

#include "ChunkManager.h"
#include "Player.h"

Camera::Camera(Player& player)
	: player{&player}
{
	this->view.setSize(WindowSize::Width, WindowSize::Height);
}

void Camera::update(sf::RenderWindow& window)
{
	this->view.setCenter({ this->player->getPosition() });
	window.setView(this->view);
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

void Camera::clampViewSize()
{
	sf::Vector2f viewSize = this->view.getSize();
	this->view.setSize(std::clamp(viewSize.x, ViewSize::Min, ViewSize::Max),
		std::clamp(viewSize.y, ViewSize::Min, ViewSize::Max));
}