//
// Created by Eryk on 23.12.2020.
//

#ifndef SIMPLERPG_RIFLEAMMO_H
#define SIMPLERPG_RIFLEAMMO_H

#include "Bullet.h"

class RifleAmmo: public Bullet
{
public:
	explicit RifleAmmo();

	void update(float const& deltaTime) override;
	void hit() override;

private:
	float lifeTime;
};


#endif //SIMPLERPG_RIFLEAMMO_H
