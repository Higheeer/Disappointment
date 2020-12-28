//
// Created by Eryk on 21.12.2020.
//

#ifndef SIMPLERPG_WEAPON_H
#define SIMPLERPG_WEAPON_H

#include <memory>

#include <SFML/Graphics/Drawable.hpp>

class Bullet;

class Weapon: public sf::Drawable
{
public:
	virtual ~Weapon() = default;

	virtual void shoot() = 0;
	virtual void reload() = 0;
	virtual void update(float const& deltaTime, sf::Vector2f const& playerPosition) = 0;
};

#endif //SIMPLERPG_WEAPON_H
