//
// Created by Eryk on 23.12.2020.
//

#ifndef SIMPLERPG_RIFLE_H
#define SIMPLERPG_RIFLE_H

#include <string>

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Weapon.h"
#include "Bullet.h"

class Rifle: public Weapon
{
public:
	explicit Rifle(std::string name, sf::RenderWindow& window);

	void shoot() override;
	void reload() override;
	void update(float const& deltaTime, sf::RectangleShape const& playerBody) override;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::RenderWindow& window;

	std::string name;
	unsigned int magazineSize;
	unsigned int bulletsInMagazine;
	sf::RectangleShape body;
	sf::Vector2f position;

	std::vector<Bullet> activeBullets;
};


#endif //SIMPLERPG_RIFLE_H