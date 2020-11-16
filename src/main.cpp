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

	Camera camera{ player };
	sf::Clock clock;

	Terrain::ChunkManager chunkManager;

	while (window.isOpen())
	{
		window.clear();
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

			if (event.type == sf::Event::MouseWheelScrolled)
			{
				if (event.mouseWheelScroll.delta > 0)
					camera.zoomOut();
				if (event.mouseWheelScroll.delta < 0)
					camera.zoomIn();
			}
		}
		chunkManager.generateTerrain(player);

		camera.update(chunkManager, window);
		player.update(deltaTime, window);

		window.draw(camera);
		player.draw(window);
		window.display();
	}

	return 0;
}
