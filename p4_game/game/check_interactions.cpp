// check_interactions.cpp
// Francisco Puertas Rodríguez
// fpuertasrodriguez@gmail.com

#include "stdafx.h"
#include "check_interactions.h"

void checkKillEnemy(std::list<CBullet>::iterator oBullet, std::list<CEnemy>::iterator oEnemy)
{
	unsigned int iPositionBullet = oBullet->getPositionBullet();
	unsigned int iPositionEnemy = oEnemy->getPositionEnemy();
	
	if ((abs(static_cast<int>(iPositionEnemy - iPositionBullet)) <= 1) && (oBullet->getBullet() == true))
	{
		updateWorld(FIGURE_WORLD, iPositionBullet);
		updateWorld(FIGURE_WORLD, iPositionEnemy);
		oEnemy->setPositionEnemy(-1);
		oBullet->setBullet(false);
		oBullet->setPositionBullet(TAM_WORLD);
		updateScore(1);
	}
}

bool checkDeath(CEnemy oEnemy)
{
	if ((abs(static_cast<int>(oEnemy.getPositionEnemy() - getPositionHuman())) <= 1))
	{
		return false;
	}

	return true;
}

void updateList()
{
	std::list<CEnemy>::iterator itEnemy = lEnemy.begin();
	std::list<CBullet>::iterator itBullet = lBullet.begin();

	while (itEnemy != lEnemy.end())
	{
		if (itEnemy->getPositionEnemy() != -1)
		{
			itEnemy++;
		}
		else
		{
			itEnemy = lEnemy.erase(itEnemy);
		}
	}

	while (itBullet != lBullet.end())
	{
		if (itBullet->getBullet())
		{
			itBullet++;
		}
		else
		{
			itBullet = lBullet.erase(itBullet);
		}		
	}
}