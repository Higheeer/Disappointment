//
// Created by eryk on 27.11.2020.
//

#ifndef SIMPLERPG_GAME_H
#define SIMPLERPG_GAME_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Clock.hpp>

namespace SimpleRPG
{
	class Player;
}

namespace SimpleRPG
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
		void drawing();

	private:
		sf::RenderWindow window;
		sf::Event event;
		sf::Clock clock;
		float deltaTime;

		std::unique_ptr<Player> player;
	};
}

#endif //SIMPLERPG_GAME_H
