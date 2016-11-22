// world.cpp
// Francisco Puertas Rodríguez
// fpuertasrodriguez@gmail.com

#include "stdafx.h"
#include "world.h"
#include "check_interactions.h"

class CWorld oWorld;

CWorld::CWorld()
{
	for (unsigned int i = 0; i < TAM_WORLD; i++)
	{
		cWorld[i] = FIGURE_WORLD;
	}

	cWorld[TAM_WORLD] = '\0';
	uScore = 0;
}

CWorld::~CWorld()
{

}

void CWorld::printWorld()
{
	printf("\n\n\n\n\n\n\n\n\n\n%s", cWorld);
}

void CWorld::updateWorld(char cFigure, unsigned int iPosition)
{
	cWorld[iPosition] = cFigure;
}

void CWorld::updateScore(unsigned int uUpdateScore)
{
	uScore = uScore + uUpdateScore;
}

unsigned int CWorld::getScore()
{
	return uScore;
}

void CWorld::movementInWorld(char cFigure, unsigned int & iPosition, bool direction)
{
	if (direction)
	{
		updateWorld(FIGURE_WORLD, iPosition);

		++iPosition;

		updateWorld(cFigure, iPosition);
	}
	else if (!direction)
	{
		updateWorld(FIGURE_WORLD, iPosition);

		--iPosition;

		updateWorld(cFigure, iPosition);
	}
}

bool CWorld::updateWorld()
{
	bool bGame = true;
	std::list<CEnemy>::iterator itEnemy = lEnemy.begin();
	std::list<CBullet>::iterator itBullet = lBullet.begin();

	while (itBullet != lBullet.end())
	{
		itBullet->autoMovementBullet();
		itBullet++;
	}

	while (itEnemy != lEnemy.end())
	{
		if (bGame)
		{
			itEnemy->autoMovementEnemy();
			bGame = checkDeath(*itEnemy);

			itBullet = lBullet.begin();

			while (itBullet != lBullet.end())
			{
				checkKillEnemy(itBullet, itEnemy);
				itBullet++;
			}

			itEnemy++;
		}
		else
		{
			itEnemy++;
		}
	}

	updateList();
	updateWeather();

	return bGame;
}