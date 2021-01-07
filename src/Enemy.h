//
// Created by Eryk on 28.12.2020.
//

#ifndef DISAPPOINTMENT_ENEMY_H
#define DISAPPOINTMENT_ENEMY_H

#include <optional>

#include <SFML/Graphics/RectangleShape.hpp>

namespace Disappointment
{
	class Player;

	class Enemy : public sf::Drawable
	{
	public:
		explicit Enemy(sf::Vector2f const& position);

		void update(float delta_time, Player& player);

		void hit(unsigned short int value);
		[[nodiscard]] bool isDead() const;

		[[nodiscard]] sf::FloatRect bodyBounds() const;

	private:
		void playerDetection(Player& player, float delta_time);
		[[nodiscard]] bool isInFieldOfView(Player const& player) const;
		void moveToLatestKnownPosition(float delta_time);
		void rotateToLatestKnownPosition();

		void cooldownTimer(float delta_time);

		void attack(Player& player);

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:
		unsigned int strength;
		short int health;
		float speed;

		float attack_cooldown;
		float cooldown_timer;
		bool is_on_cooldown;

		float field_of_view_offset;
		std::optional<sf::Vector2f> latest_known_position;

		sf::RectangleShape body;
	};
}

#endif //DISAPPOINTMENT_ENEMY_H
