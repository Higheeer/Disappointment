#include <cmath>
#include <iostream>

#include "Player.h"
#include "Camera.h"
#include "Constants.h"

//@TODO Poprawić czytelność kodu
//@TODO Zacząć robić jakiś world generator i world loader

int main()
{
	sf::RenderWindow window{ sf::VideoMode(WindowSize::Width, WindowSize::Height), "Simple RPG" };
	window.setFramerateLimit(60);
	window.setMouseCursorGrabbed(true);

	sf::Texture playerTexture;
	playerTexture.loadFromFile("../res/textures/test.png");

	Player player{{ 15, 15 }, playerTexture };

	Camera camera{ player };
	sf::Clock clock;

	Terrain terrain{ 5 };

	while (window.isOpen())
	{
		//float deltaTime = clock.getElapsedTime().asSeconds();
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
		terrain.generateTerrain(player);

		camera.update(terrain, window);
		player.update();

		window.clear();
		window.draw(camera);
		player.draw(window);
		window.display();
	}

	return 0;
}
