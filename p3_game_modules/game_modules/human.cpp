// human.cpp
// Francisco Puertas Rodr�guez
// fpuertasrodriguez@gmail.com

#include "stdafx.h"
#include "human.h"

static unsigned int iPositionHuman = TAM_WORLD / 2;

void initHuman()
{
	updateWorld(FIGURE_HUMAN, TAM_WORLD/2);
}

void movementHuman(int iBottonPress)
{
	// If the button pressed is 'a', the FIGURE_HUMAN moves to the left
	if (iBottonPress == 97 && iPositionHuman != 0)
	{
		updateWorld(FIGURE_WORLD, iPositionHuman);

		--iPositionHuman;

		updateWorld(FIGURE_HUMAN, iPositionHuman);
	}
	// If the button pressed is 'd', the FIGURE_HUMAN moves to the right
	else if (iBottonPress == 100 && iPositionHuman != TAM_WORLD - 1)
	{
		updateWorld(FIGURE_WORLD, iPositionHuman);

		++iPositionHuman;

		updateWorld(FIGURE_HUMAN, iPositionHuman);
	}
}

unsigned int getPositionHuman()
{
	return iPositionHuman;
}