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
		explicit Bullet(sf::Vector2f const& position, sf::Vector2f const& move_direction, float angle);

		void update(float delta_time, std::vector<Enemy>& enemies);
		bool shouldBeDestroyed() const; //TODO wymyślić lepszą nazwe tej metody

	private:
		void hitTheEnemy(std::vector<Enemy>& enemies);

	private:
		float existence_time; //TODO nadać bardziej obrazową nazwę tej zmiennej
		sf::Vector2f move_direction;
		bool destroyed; //TODO nadać bardziej obrazową nazwę tej zmiennej
	};
}

#endif //DISAPPOINTMENT_BULLET_H
