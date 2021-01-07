//
// Created by Eryk on 21.12.2020.
//

#ifndef DISAPPOINTMENT_WEAPON_H
#define DISAPPOINTMENT_WEAPON_H

#include <memory>

#include <SFML/Graphics/Drawable.hpp>

namespace Disappointment
{
	class Enemy;

	class Weapon : public sf::Drawable
	{
	public:
		virtual void shoot(float delta_time, sf::Vector2f const& player_position) = 0;
		virtual void reload() = 0;
		virtual void update(float delta_time, std::vector<Enemy>& enemies) = 0;

		[[nodiscard]] virtual unsigned short int bulletsLeft() const = 0;
		[[nodiscard]] virtual unsigned short int magazineSize() const = 0;
	};
}
#endif //DISAPPOINTMENT_WEAPON_H
