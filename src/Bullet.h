//
// Created by Eryk on 23.12.2020.
//

#ifndef SIMPLERPG_BULLET_H
#define SIMPLERPG_BULLET_H

#include <SFML/Graphics/RectangleShape.hpp>

class Bullet: public sf::RectangleShape
{
protected:
	virtual void update(float const& deltaTime) = 0;
	virtual void hit() = 0;
};

#endif //SIMPLERPG_BULLET_H
