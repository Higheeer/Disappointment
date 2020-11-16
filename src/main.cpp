#include <SFML/Graphics/Texture.hpp>

#include "Player.h"
#include "ChunkManager.h"
#include "Camera.h"

int main()
{
	sf::RenderWindow window{ sf::VideoMode(WindowSize::Width, WindowSize::Height), "Simple RPG" };
	window.setFramerateLimit(60);
	window.setMouseCursorGrabbed(true);

	sf::Texture playerTexture;
	playerTexture.loadFromFile("../res/textures/Player.png");

	Player player{{ 15, 15 }, playerTexture };

	sf::Clock clock;

	Terrain::ChunkManager chunkManager;

	while (window.isOpen())
	{

		float deltaTime = clock.getElapsedTime().asSeconds();
		clock.restart();

		sf::Event event{};
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
		player.input(event, deltaTime);
		chunkManager.generateTerrain(player);
		player.update(deltaTime, window);

		window.clear();
		player.draw(window);
		window.display();
	}
}
