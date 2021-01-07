//
// Created by Eryk on 04.01.2021.
//

#ifndef DISAPPOINTMENT_ENEMYSUPERVISOR_H
#define DISAPPOINTMENT_ENEMYSUPERVISOR_H

#include <SFML/Graphics/Texture.hpp>

#include "Enemy.h"

namespace Disappointment
{
	class Player;

	class EnemySupervisor : public sf::Drawable
	{
	public:
		explicit EnemySupervisor(Player& player);

		void update(float delta_time);
		std::vector<Enemy>& getEnemies();

	private:
		void createEnemy();
		void removeAll();

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:
		std::vector<Enemy> enemies;
		Player* player;
	};
}

#endif //DISAPPOINTMENT_ENEMYSUPERVISOR_H
