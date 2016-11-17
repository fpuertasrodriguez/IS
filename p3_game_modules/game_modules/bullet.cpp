// bullet.cpp
// Francisco Puertas Rodríguez
// fpuertasrodriguez@gmail.com

#include "stdafx.h"
#include "bullet.h"

static bool bBullet = false;
static bool bBulletDirection = false;
static unsigned int iPositionBullet;

void shootBullet(int iBottonPress)
{
	if (!bBullet)
	{
		unsigned int iPositionHuman = getPositionHuman();

		// If the button pressed is 'q', the FIGURE_BULLET_LEFT moves to the left
		if (iBottonPress == 113 && iPositionHuman != 0)
		{
			iPositionHuman = iPositionHuman - 1;

			updateWorld(FIGURE_BULLET_LEFT, iPositionHuman);

			bBulletDirection = false;
			bBullet = true;
		}
		// If the button pressed is 'e', the FIGURE_BULLET_RIGHT moves to the right
		else if (iBottonPress == 101 && iPositionHuman != TAM_WORLD - 1)
		{
			iPositionHuman = iPositionHuman + 1;

			updateWorld(FIGURE_BULLET_RIGHT, iPositionHuman);

			bBulletDirection = true;
			bBullet = true;
		}

		iPositionBullet = iPositionHuman;
	}
}

void setBullet(bool bUpdateBullet)
{
	bBullet = bUpdateBullet;
}

bool getBullet()
{
	return bBullet;
}

void autoMovementBullet()
{
	if (bBullet == true && (iPositionBullet == 0 || iPositionBullet == TAM_WORLD- 1))
	{
		bBullet = false;

		if (bBulletDirection)
		{
			updateWorld(FIGURE_WORLD, TAM_WORLD - 1);
		}
		else
		{
			updateWorld(FIGURE_WORLD, 0);
		}
	}
	else if (bBullet == true && (iPositionBullet != 0 || iPositionBullet != TAM_WORLD - 1))
	{
		if (bBulletDirection)
		{
			movementInWorld(FIGURE_BULLET_RIGHT, iPositionBullet, bBulletDirection);
		}
		else
		{
			movementInWorld(FIGURE_BULLET_LEFT, iPositionBullet, bBulletDirection);
		}
	}
}

unsigned int getPositionBullet()
{
	return iPositionBullet;
}

void setPositionBullet(int iNum)
{
	iPositionBullet = iNum;
}