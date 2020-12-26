//
// Created by eryk on 27.11.2020.
//

#include "Game.h"

#include "Constants.h"
#include "Player.h"

using namespace SimpleRPG;

Game::Game()
		: window{sf::VideoMode(WindowSize::Width, WindowSize::Height), "Simple RPG"}, event{}, clock{}, deltaTime{}
{
	window.setFramerateLimit(60);
	window.setMouseCursorGrabbed(true);

	texture.loadFromFile("res/textures/player.png");
	player = std::make_unique<Player>(sf::Vector2f{128.0f, 128.0f}, texture, window);
}

void Game::run()
{
	while (window.isOpen())
	{
		deltaTime = clock.getElapsedTime().asSeconds();
		clock.restart();

		eventHandle();
		inputHandle();
		update();
		drawing();
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
	}
}

void Game::inputHandle()
{
	player->input(deltaTime);
}

void Game::update()
{
	player->update(deltaTime);
}

void Game::drawing()
{
	window.clear();
	window.draw(*player);
	window.display();
}




