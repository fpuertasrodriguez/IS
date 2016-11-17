// enemy.cpp
// Francisco Puertas Rodríguez
// fpuertasrodriguez@gmail.com

#include "stdafx.h"
#include "enemy.h"

static int iPositionEnemy = -1;
static bool bEnemy = true;

void initEnemy()
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

void autoMovementEnemy()
{
	if (((iPositionEnemy != 0 || bEnemy) && (iPositionEnemy != TAM_WORLD - 1 || !bEnemy)))
	{
		if (bEnemy)
		{
			updateWorld(FIGURE_WORLD, iPositionEnemy);

			++iPositionEnemy;

			updateWorld(FIGURE_ENEMY, iPositionEnemy);
		}
		else if (iPositionEnemy != 0)
		{
			updateWorld(FIGURE_WORLD, iPositionEnemy);

			--iPositionEnemy;

			updateWorld(FIGURE_ENEMY, iPositionEnemy);
		}
	}
}

int getPositionEnemy()
{
	return iPositionEnemy;
}

void setPositionEnemy(int iNum)
{
	iPositionEnemy = iNum;
}

void setEnemy(bool bUpdateEnemy)
{
	bEnemy = bUpdateEnemy;
}