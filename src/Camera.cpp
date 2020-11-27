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