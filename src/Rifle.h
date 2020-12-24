//
// Created by Eryk on 23.12.2020.
//

#ifndef SIMPLERPG_RIFLE_H
#define SIMPLERPG_RIFLE_H

#include <string>

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Weapon.h"

class Rifle: public Weapon
{
public:
	explicit Rifle(std::string name);

	void shoot() override;
	void reload() override;
	void update(float const& deltaTime, sf::Vector2f const& position, sf::RenderWindow const& window) override;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	std::string name;
	unsigned int magazineSize;
	unsigned int bulletsInMagazine{20};
	sf::RectangleShape body;
};


#endif //SIMPLERPG_RIFLE_H
