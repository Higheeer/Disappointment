//
// Created by Eryk on 25.12.2020.
//

#ifndef SIMPLERPG_BULLET_H
#define SIMPLERPG_BULLET_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Bullet : public sf::RectangleShape
{
public:
	explicit Bullet(sf::Vector2f const& position, sf::Vector2f const& direction, float angle);

	void update(float deltaTime);
	bool shouldBeDestroyed() const;

private:
	float lifeTime;
	sf::Vector2f direction;
};


#endif //SIMPLERPG_BULLET_H
