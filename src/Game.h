//
// Created by eryk on 27.11.2020.
//

#ifndef DISAPPOINTMENT_GAME_H
#define DISAPPOINTMENT_GAME_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Clock.hpp>

#include <SFML/Graphics/Texture.hpp>

#include "Player.h"
#include "EnemySupervisor.h"
#include "HUD.h"

namespace Disappointment
{
	class Game
	{
	public:
		Game();
		void run();

	private:
		void eventHandle();
		void inputHandle();
		void update();
		void draw();

	private:
		sf::RenderWindow window;
		sf::Event event;
		sf::Clock clock;
		float delta_time;

		sf::Texture texture;
		std::unique_ptr<Player> player;
		std::unique_ptr<HUD> hud;

		std::unique_ptr<EnemySupervisor> enemies;
	};
}

#endif //DISAPPOINTMENT_GAME_H
