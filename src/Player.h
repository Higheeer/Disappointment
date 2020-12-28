//
// Created by Eryk on 20.10.2020.
//

#ifndef SIMPLERPG_PLAYER_H
#define SIMPLERPG_PLAYER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Vector2.hpp>

class Weapon;

namespace SimpleRPG
{
	class Player : public sf::Drawable
	{
	public:
		Player(sf::Vector2f const& position, sf::Texture const& texture, sf::RenderWindow& window);

		void input(float const& deltaTime);
		void update(float const& deltaTime);
		sf::FloatRect getBody() const;

	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:
		void move(float const& deltaTime);
		void rotation();

	private:
		sf::Vector2f position;
		sf::Vector2f size;

		sf::RenderWindow& window;

		sf::RectangleShape body;
		std::unique_ptr<Weapon> weapon;
	};

	float normalize(float value);
}
#endif //SIMPLERPG_PLAYER_H
