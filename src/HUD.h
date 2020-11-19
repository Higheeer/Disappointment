//
// Created by eryk on 19.11.2020.
//

#ifndef SIMPLERPG_HUD_H
#define SIMPLERPG_HUD_H

#include <map>

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Drawable.hpp>

namespace sf
{
	class RenderWindow;
}

namespace Terrain
{
	class ChunkManager;

	class Chunk;
}

class Player;

class HUD : public sf::Drawable
{
public:
	explicit HUD(sf::RenderWindow& window);

	void update(sf::Vector2f const& playerPosition, unsigned int const& amountOfChunks);

private:
	void updatePlayerPosition(sf::Vector2f const& playerPosition, sf::Vector2f const& textPosition);

	void updateAmountOfChunks(unsigned int const& amountOfChunks, sf::Vector2f const& textPosition);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::RenderWindow* window;

	sf::Font font;
	std::map<std::string, sf::Text> text;
};

#endif //SIMPLERPG_HUD_H
