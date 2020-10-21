//
// Created by Eryk on 20.10.2020.
//

#ifndef SIMPLERPG_KEYBOARD_H
#define SIMPLERPG_KEYBOARD_H

class Player;

class Keyboard
{
 public:
	Keyboard() = default;

	static void playerMovementControl(Player& player, float const& deltaTime);
};

#endif //SIMPLERPG_KEYBOARD_H
