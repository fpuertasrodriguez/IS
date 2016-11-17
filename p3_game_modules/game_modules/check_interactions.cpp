// check_interactions.cpp
// Francisco Puertas Rodríguez
// fpuertasrodriguez@gmail.com

#include "stdafx.h"
#include "check_interactions.h"

void checkKillEnemy()
{
	unsigned int iPositionBullet = getPositionBullet();
	unsigned int iPositionEnemy = getPositionEnemy();

	if ((abs(static_cast<int>(iPositionEnemy - iPositionBullet)) <= 1) && (getBullet() == true))
	{
		updateWorld(FIGURE_WORLD, iPositionBullet);
		updateWorld(FIGURE_WORLD, iPositionEnemy);
		setPositionEnemy(-1);
		setBullet(false);
		setEnemy(true);
		setPositionBullet(TAM_WORLD);
		updateScore(1);
	}	
}

bool checkDeath()
{
	if (getPositionEnemy() == getPositionHuman())
	{
		return false;
	}

	return true;
}