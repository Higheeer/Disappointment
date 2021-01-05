//
// Created by Eryk on 04.01.2021.
//

#include "EnemySupervisor.h"

#include "Player.h"
#include "Utilities/RandomNumberGenerator.h"


using namespace SimpleRPG;

EnemySupervisor::EnemySupervisor(Player& player, unsigned short int amount_of_enemies)
		: player(&player)
{
	enemies.reserve(amount_of_enemies);

	for(auto i = 0; i < amount_of_enemies; ++i)
	{
		createEnemy();
	}

}

void EnemySupervisor::createEnemy()
{
	enemies.emplace_back(sf::Vector2f(RandomNumberGenerator::getNumber(25,500),RandomNumberGenerator::getNumber(25,500)));
}

void EnemySupervisor::removeAll()
{
	enemies.clear();
}

void EnemySupervisor::update(float delta_time)
{
	for(auto& i: enemies)
	{
		i.update(delta_time, *player);
	}
}

void EnemySupervisor::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for(auto const& i : enemies)
	{
		target.draw(i);
	}
}
