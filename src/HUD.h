//
// Created by Eryk on 04.01.2021.
//

#ifndef SIMPLERPG_HUD_H
#define SIMPLERPG_HUD_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

namespace SimpleRPG
{
	class Player;

	class HUD : public sf::Drawable
	{
	public:
		explicit HUD();

		void update(Player const& player, sf::RenderTarget const& target);

	private:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:
		sf::Font font;
		sf::Text text;
	};

}


#endif //SIMPLERPG_HUD_H
