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

namespace SimpleRPG
{
	class Player : public sf::Drawable
	{
	public:
		struct Attributes
		{
			short int max_health;
			short int health;
		};

		Player(sf::Vector2f const& position, sf::Texture const& texture, sf::RenderWindow& window);

		void input(float delta_time);
		void event(sf::Event const& event);
		void update(float delta_time);

		void hit(unsigned short int value);
		bool isDead() const;

		sf::FloatRect bodyBounds() const;
		std::string health() const;

	private:
		void move(float delta_time);
		void rotation();

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:
		Attributes attribs;

		sf::RectangleShape body;
		sf::RenderWindow& window;
	};

	float normalize(float value);
}
#endif //SIMPLERPG_PLAYER_H
