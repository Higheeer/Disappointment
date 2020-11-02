//
// Created by Eryk on 01.11.2020.
//

#ifndef SIMPLERPG_SRC_MOUSE_H_
#define SIMPLERPG_SRC_MOUSE_H_

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Player;

class Mouse
{
 public:
	explicit Mouse(Player& player);

	[[noreturn]] void update(float const& deltaTime);

	void leftClick(sf::RenderWindow& window);

 private:

	[[nodiscard]] bool playerReachedDestination() const;

	[[nodiscard]] static sf::Vector2f calculateDistance(sf::Vector2f const& start, sf::Vector2f const& end);

	[[nodiscard]] static float calculateLength(sf::Vector2f const& distance);

	[[nodiscard]] static sf::Vector2f normalize(sf::Vector2f const& vectorToNormalize, float const& length);

 private:
	Player* player;

	bool isSetDestination;
	sf::Vector2f destination;

	sf::Vector2f direction;
	float const speed;
};

#endif //SIMPLERPG_SRC_MOUSE_H_
