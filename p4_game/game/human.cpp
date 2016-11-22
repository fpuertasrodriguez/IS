// human.cpp
// Francisco Puertas Rodríguez
// fpuertasrodriguez@gmail.com

#include "stdafx.h"
#include "human.h"
static unsigned int uPositionHuman = TAM_WORLD / 2;

void initHuman()
{
	updateWorld(FIGURE_HUMAN, TAM_WORLD/2);
}

void movementHuman(unsigned int uBottonPress)
{
	// If the button pressed is 'a', the FIGURE_HUMAN moves to the left
	if (uBottonPress == 97 && uPositionHuman != 0)
	{
		movementInWorld(FIGURE_HUMAN, uPositionHuman, false);
	}
	// If the button pressed is 'd', the FIGURE_HUMAN moves to the right
	else if (uBottonPress == 100 && uPositionHuman != TAM_WORLD - 1)
	{
		movementInWorld(FIGURE_HUMAN, uPositionHuman, true);
	}
}

unsigned int getPositionHuman()
{
	return uPositionHuman;
}