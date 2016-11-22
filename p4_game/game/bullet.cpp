// bullet.cpp
// Francisco Puertas Rodríguez
// fpuertasrodriguez@gmail.com

#include "stdafx.h"
#include "bullet.h"

std::list<CBullet> lBullet;

CBullet::CBullet()
{
	bBullet = false;
	bDirectionBullet = false;
	uPositionBullet = 0;
}

CBullet::~CBullet()
{
}

void createBullet(unsigned int uBottonPress)
{
	CBullet oBullet;
	
	if (!oBullet.getBullet())
	{
		unsigned int uPositionHuman = getPositionHuman();

		// If the button pressed is 'q', the FIGURE_BULLET_LEFT moves to the left
		if (uBottonPress == 113 && uPositionHuman != 0)
		{
			uPositionHuman = uPositionHuman - 1;

			updateWorld(FIGURE_BULLET_LEFT, uPositionHuman);

			oBullet.setDirectionBullet(false);
			oBullet.setBullet(true);
		}
		// If the button pressed is 'e', the FIGURE_BULLET_RIGHT moves to the right
		else if (uBottonPress == 101 && uPositionHuman != TAM_WORLD - 1)
		{
			uPositionHuman = uPositionHuman + 1;

			updateWorld(FIGURE_BULLET_RIGHT, uPositionHuman);

			oBullet.setDirectionBullet(true);
			oBullet.setBullet(true);
		}

		oBullet.setPositionBullet(uPositionHuman);
		lBullet.push_back(oBullet);
	}
}

void CBullet::setBullet(bool bUpdateBullet)
{
	bBullet = bUpdateBullet;
}

bool CBullet::getBullet()
{
	return bBullet;
}

void CBullet::autoMovementBullet()
{
	if (bBullet == true && (uPositionBullet == 0 || uPositionBullet == TAM_WORLD- 1))
	{
		bBullet = false;

		if (bDirectionBullet)
		{
			updateWorld(FIGURE_WORLD, TAM_WORLD - 1);
		}
		else
		{
			updateWorld(FIGURE_WORLD, 0);
		}
	}
	else if (bBullet == true && (uPositionBullet != 0 || uPositionBullet != TAM_WORLD - 1))
	{
		if (bDirectionBullet)
		{
			movementInWorld(FIGURE_BULLET_RIGHT, uPositionBullet, bDirectionBullet);
		}
		else
		{
			movementInWorld(FIGURE_BULLET_LEFT, uPositionBullet, bDirectionBullet);
		}
	}
}

unsigned int CBullet::getPositionBullet()
{
	return uPositionBullet;
}

void CBullet::setPositionBullet(unsigned int uNum)
{
	uPositionBullet = uNum;
}

void CBullet::setDirectionBullet(bool bDirection)
{
	bDirectionBullet = bDirection;
}

bool CBullet::getDirectionBullet()
{
	return bDirectionBullet;
}