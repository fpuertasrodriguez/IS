// enemy.cpp
// Francisco Puertas Rodríguez
// fpuertasrodriguez@gmail.com

#include "stdafx.h"
#include "enemy.h"

std::list<CEnemy> lEnemy;

CEnemy::CEnemy()
{
	iPositionEnemy = -1;
	bEnemy = true;
}

CEnemy::~CEnemy()
{
}

void createEnemy()
{
	CEnemy oEnemy;
	
	if (oEnemy.getPositionEnemy() == -1)
	{
		oEnemy.setPositionEnemy(rand() % 2);

		if (oEnemy.getPositionEnemy() == 1)
		{
			oEnemy.setPositionEnemy(TAM_WORLD - 1);
			oEnemy.setEnemy(false);
		}
		
		oWorld.updateWorld(FIGURE_ENEMY, oEnemy.getPositionEnemy());
		lEnemy.push_back(oEnemy);
	}
}

void CEnemy::autoMovementEnemy()
{
	if (((iPositionEnemy != 0 || bEnemy) && (iPositionEnemy != TAM_WORLD - 1 || !bEnemy)))
	{
		oWorld.movementInWorld(FIGURE_ENEMY, (unsigned int &)iPositionEnemy, bEnemy);
	}
}

int CEnemy::getPositionEnemy()
{
	return iPositionEnemy;
}

void CEnemy::setPositionEnemy(int iNum)
{
	iPositionEnemy = iNum;
}

void CEnemy::setEnemy(bool bUpdateEnemy)
{
	bEnemy = bUpdateEnemy;
}