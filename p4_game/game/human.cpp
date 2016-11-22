// human.cpp
// Francisco Puertas Rodríguez
// fpuertasrodriguez@gmail.com

#include "stdafx.h"
#include "human.h"

class CHuman oHuman;

CHuman::CHuman()
{
	uPositionHuman = TAM_WORLD / 2;
	oWorld.updateWorld(FIGURE_HUMAN, TAM_WORLD / 2);
}

CHuman::~CHuman()
{

}

void CHuman::movementHuman(unsigned int uBottonPress)
{
	// If the button pressed is 'a', the FIGURE_HUMAN moves to the left
	if (uBottonPress == 97 && uPositionHuman != 0)
	{
		oWorld.movementInWorld(FIGURE_HUMAN, uPositionHuman, false);
	}
	// If the button pressed is 'd', the FIGURE_HUMAN moves to the right
	else if (uBottonPress == 100 && uPositionHuman != TAM_WORLD - 1)
	{
		oWorld.movementInWorld(FIGURE_HUMAN, uPositionHuman, true);
	}
}

unsigned int CHuman::getPositionHuman()
{
	return uPositionHuman;
}