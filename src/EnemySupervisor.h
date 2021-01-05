//
// Created by Eryk on 04.01.2021.
//

#ifndef SIMPLERPG_ENEMYSUPERVISOR_H
#define SIMPLERPG_ENEMYSUPERVISOR_H

#include "Enemy.h"

namespace SimpleRPG
{
	class Player;

	class EnemySupervisor : public sf::Drawable
	{
	public:
		explicit EnemySupervisor(Player& player, unsigned short int amount_of_enemies);

		void update(float delta_time);

	private:
		void createEnemy();
		void removeAll();

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:
		std::vector<Enemy> enemies;
		Player* player;
	};
}

#endif //SIMPLERPG_ENEMYSUPERVISOR_H
