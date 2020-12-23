//
// Created by Eryk on 23.12.2020.
//

#ifndef SIMPLERPG_RIFLE_H
#define SIMPLERPG_RIFLE_H

#include <string>

#include <SFML/Graphics/RectangleShape.hpp>

#include "Weapon.h"

class Rifle: public Weapon
{
public:
	explicit Rifle(std::string const& name);

	void shoot() override;
	void reload() override;
	void update(float const& deltaTime) override;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	std::string name;
	unsigned int magazineSize;
	sf::RectangleShape body;
	std::vector<std::unique_ptr<Bullet>> activeBullets;
};


#endif //SIMPLERPG_RIFLE_H
