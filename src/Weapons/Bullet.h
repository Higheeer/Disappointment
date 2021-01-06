//
// Created by Eryk on 25.12.2020.
//

#ifndef DISAPPOINTMENT_BULLET_H
#define DISAPPOINTMENT_BULLET_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace Disappointment
{
	class Enemy;

	class Bullet : public sf::RectangleShape
	{
	public:
		explicit Bullet(sf::Vector2f const& position, sf::Vector2f const& direction, float angle);

		void update(float delta_time,std::vector<Enemy>& enemy);
		bool shouldBeDestroyed() const;

	private:
		float life_time;
		sf::Vector2f direction;
		bool should_destroy;
	};
}

#endif //DISAPPOINTMENT_BULLET_H
