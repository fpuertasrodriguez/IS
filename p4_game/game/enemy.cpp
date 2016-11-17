// enemy.cpp
// Francisco Puertas Rodríguez
// fpuertasrodriguez@gmail.com

#include "stdafx.h"
#include "enemy.h"

std::vector<CEnemy> vEnemy;

CEnemy::CEnemy()
{
	iPositionEnemy = -1;
	bEnemy = true;
}

CEnemy::~CEnemy()
{
}

void CEnemy::initEnemy()
{
	if (iPositionEnemy == -1)
	{
		iPositionEnemy = rand() % 2;

		if (iPositionEnemy == 1)
		{
			iPositionEnemy = TAM_WORLD - 1;
			bEnemy = false;
		}

		updateWorld(FIGURE_ENEMY, iPositionEnemy);
	}
}

void CEnemy::autoMovementEnemy()
{
	if (((iPositionEnemy != 0 || bEnemy) && (iPositionEnemy != TAM_WORLD - 1 || !bEnemy)))
	{
		movementInWorld(FIGURE_ENEMY, (unsigned int &)iPositionEnemy, bEnemy);		
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