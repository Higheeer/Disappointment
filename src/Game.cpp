//
// Created by eryk on 27.11.2020.
//

#include <iostream>
#include "Game.h"

#include "Utilities/Constants.h"

using namespace Disappointment;

Game::Game()
		: window{ sf::VideoMode(WindowSize::width, WindowSize::height), "Simple RPG" }, event{}, clock{}, delta_time{}
{
	window.setFramerateLimit(60);
	window.setMouseCursorGrabbed(true);

	player = std::make_unique<Player>(sf::Vector2f{ 128.0f, 128.0f }, window);

	enemies = std::make_unique<EnemySupervisor>(*player);

	hud = std::make_unique<HUD>();
}

void Game::run()
{
	while (window.isOpen())
	{
		delta_time = clock.getElapsedTime().asSeconds();
		clock.restart();

		eventHandle();
		inputHandle();
		update();
		draw();
	}
}

void Game::eventHandle()
{
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}

		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
		{
			window.close();
		}

		player->event(event);
	}
}

void Game::inputHandle()
{
	player->input(delta_time);
}

void Game::update()
{
	player->update(delta_time, enemies->getEnemies());
	enemies->update(delta_time);
	hud->update(*player, window);
}

void Game::draw()
{
	window.clear(sf::Color(0, 51, 0));
	window.draw(*player);
	window.draw(*enemies);
	window.draw(*hud);
	window.display();
}




