#include <iostream>

#include "Player.h"
#include "Keyboard.h"

#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window{ sf::VideoMode(1024, 960), "Simple RPG" };
	window.setFramerateLimit(60);

	sf::Texture playerTexture;
	playerTexture.loadFromFile("../res/textures/test.png");

	Player player{{ 340, 63 }, playerTexture };

	sf::Clock clock;
	while (window.isOpen())
	{
		float deltaTime = clock.getElapsedTime().asSeconds();
		clock.restart();

		sf::Event event{};
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

		}
		Keyboard::playerMovementControl(player, deltaTime);
		player.update(deltaTime);

		window.clear();
		player.draw(window);
		window.display();
	}

	return 0;
}
