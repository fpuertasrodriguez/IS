// world.cpp
// Francisco Puertas Rodríguez
// fpuertasrodriguez@gmail.com

#include "stdafx.h"
#include "world.h"
#include "check_interactions.h"
static char cWorld[TAM_WORLD + 1];
static unsigned int uScore = 0;

void initWorld()
{
	for (unsigned int i = 0; i < TAM_WORLD; i++)
	{
		cWorld[i] = FIGURE_WORLD;
	}

	cWorld[TAM_WORLD] = '\0';
}

void printWorld()
{
	printf("\n\n\n\n\n\n\n\n\n\n%s", cWorld);
}

void updateWorld(char cFigure, unsigned int iPosition)
{
	cWorld[iPosition] = cFigure;
}

void updateScore(unsigned int uUpdateScore)
{
	uScore = uScore + uUpdateScore;
}

unsigned int getScore()
{
	return uScore;
}

void movementInWorld(char cFigure, unsigned int & iPosition, bool direction)
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

bool updateWorld()
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