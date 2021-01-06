//
// Created by Eryk on 04.01.2021.
//

#include "EnemySupervisor.h"

#include "Player.h"
#include "Utilities/RandomNumberGenerator.h"


using namespace Disappointment;

EnemySupervisor::EnemySupervisor(Player& player)
		: player(&player)
{
	enemies.reserve(50);

	texture.loadFromFile("res/textures/Zombie.png");

	for (auto i = 0; i < 50; ++i)
	{
		createEnemy();
	}
}

void EnemySupervisor::createEnemy()
{
	enemies.emplace_back(
			sf::Vector2f(RandomNumberGenerator::getNumber(25, 1500), RandomNumberGenerator::getNumber(25, 500)),
			texture);
}

void EnemySupervisor::removeAll()
{
	enemies.clear();
}

void EnemySupervisor::update(float delta_time)
{
	for (auto& i: enemies)
	{
		i.update(delta_time, *player);
	}

	enemies.erase(std::remove_if(enemies.begin(), enemies.end(),
			[](Enemy const& b)
			{ return b.isDead(); }), enemies.end());
}

std::vector<Enemy>& EnemySupervisor::getEnemies()
{
	return enemies;
}

void EnemySupervisor::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto const& i : enemies)
	{
		target.draw(i);
	}
}


