//
// Created by Eryk on 22.10.2020.
//

#ifndef SIMPLERPG_SRC_CAMERA_H_
#define SIMPLERPG_SRC_CAMERA_H_

#include <SFML/Graphics/RenderWindow.hpp>

#include "Constants.h"

class Player;

class Camera
{
public:
	explicit Camera(Player& player);

	void zoomIn();

	void zoomOut();

	void update(sf::RenderWindow& window);

private:
	void clampViewSize();

private:
	sf::View view;
	Player* player;
};

#endif //SIMPLERPG_SRC_CAMERA_H_
