//
// Created by Eryk on 28.12.2020.
//

#ifndef SIMPLERPG_ENEMY_H
#define SIMPLERPG_ENEMY_H

#include <SFML/Graphics/RectangleShape.hpp>

namespace SimpleRPG
{
	class Player;

	class Enemy : public sf::Drawable
	{
	public:
		explicit Enemy(sf::Vector2f const& position);

		void update(float delta_time, Player& player);

		void attack(Player& player);
		void hit(unsigned short int value);
		bool isDead() const;

		sf::FloatRect bodyBounds() const;

	private:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:
		unsigned int strength;
		short int health;
		float speed;

		float attack_cooldown;
		float cooldown_timer;
		bool is_on_cooldown;

		sf::RectangleShape body;
	};
}

#endif //SIMPLERPG_ENEMY_H
