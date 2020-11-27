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

}

void Game::update()
{

}

void Game::drawing()
{
	window.clear();
	window.display();
}




