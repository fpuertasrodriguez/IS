// world.cpp
// Francisco Puertas Rodríguez
// fpuertasrodriguez@gmail.com

#include "stdafx.h"
#include "world.h"

static char cWorld[TAM_WORLD + 1];
static int iScore = 0;

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

void updateScore(int iUpdateScore)
{
	iScore = iScore + iUpdateScore;
}

int getScore()
{
	return iScore;
}