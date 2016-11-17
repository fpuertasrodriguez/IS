// check_interactions.cpp
// Francisco Puertas Rodríguez
// fpuertasrodriguez@gmail.com

#include "stdafx.h"
#include "check_interactions.h"

void checkKillEnemy(CBullet & oBullet, CEnemy & oEnemy)
{
	unsigned int iPositionBullet = oBullet.getPositionBullet();
	unsigned int iPositionEnemy = oEnemy.getPositionEnemy();

	if ((abs(static_cast<int>(iPositionEnemy - iPositionBullet)) <= 1) && (oBullet.getBullet() == true))
	{
		updateWorld(FIGURE_WORLD, iPositionBullet);
		updateWorld(FIGURE_WORLD, iPositionEnemy);
		oEnemy.setPositionEnemy(-1);
		oBullet.setBullet(false);
		oEnemy.setEnemy(true);
		oBullet.setPositionBullet(TAM_WORLD);
		updateScore(1);
	}	
}

bool checkDeath(CEnemy & oEnemy)
{
	if (oEnemy.getPositionEnemy() == getPositionHuman())
	{
		return false;
	}

	return true;
}