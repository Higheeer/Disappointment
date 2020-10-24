#include "Player.h"
#include "Keyboard.h"
#include "Camera.h"

//@TODO Zrobić clampowanie na kamerze (zoom)
//@TODO Poprawić czytelność kodu
//@TODO Zacząć robić jakiś world generator i world loader
//@TODO Zrobić przesuwanie kamery za pomocą myszki

int main()
{
	sf::RenderWindow window{ sf::VideoMode(1024, 960), "Simple RPG" };
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
		float deltaTime = clock.getElapsedTime().asSeconds();
		clock.restart();

		sf::Event event{};
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseWheelScrolled)
			{
				if (event.mouseWheelScroll.delta > 0)
					camera.zoomOut();
				if (event.mouseWheelScroll.delta < 0)
					camera.zoomIn();
			}

		}

		Keyboard::playerMovementControl(player, deltaTime);
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
