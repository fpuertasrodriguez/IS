// world.cpp 
// Francisco Puertas Rodriguez
// fpuertasrodriguez@gmail.com

#include "stdafx.h"
#include <conio.h>

#define TAM 21
#define FIGURE_HUMAN '-'
#define FIGURE_WORLD '_'
#define FIGURE_BULLET_LEFT '<'
#define FIGURE_BULLET_RIGHT '>'

int main()
{
	// Variable declaration 
	// World
	char cWorld[TAM + 1];

	// Human
	unsigned int  iPosition = TAM / 2;

	// Bullet
	unsigned int  iPositionBullet;
	bool bBullet = false;
	bool bBulletDirection = false;

	// Button
	unsigned int  iPress;

	// Initializaction of the world
	for (unsigned int i = 0; i < TAM; i++)
	{
		cWorld[i] = FIGURE_WORLD;
	}
	cWorld[iPosition] = FIGURE_HUMAN;
	cWorld[TAM] = '\0';

	printf("\n\n\n\n\n\n\n\n\n\n%s", cWorld);

	// Game loop
	while (1)
	{

		if (_kbhit()) // Check if a button has been pressed
		{
			iPress = _getch();

			// If the button pressed is 'a', the FIGURE_HUMAN moves to the left
			if (iPress == 97 && iPosition != 0)
			{
				cWorld[iPosition] = FIGURE_WORLD;
				--iPosition;
				cWorld[iPosition] = FIGURE_HUMAN;
			}
			// If the button pressed is 'd', the FIGURE_HUMAN moves to the right
			else if (iPress == 100 && iPosition != TAM - 1)
			{
				cWorld[iPosition] = FIGURE_WORLD;
				++iPosition;
				cWorld[iPosition] = FIGURE_HUMAN;
			}

			// If there is no bullet in play
			if (!bBullet)
			{
				// If the button pressed is 'q', the FIGURE_BULLET_LEFT moves to the left
				if (iPress == 113 && iPosition != 0)
				{
					iPositionBullet = iPosition - 1;
					cWorld[iPositionBullet] = FIGURE_WORLD;
					cWorld[iPositionBullet] = FIGURE_BULLET_LEFT;
					bBulletDirection = false;
					bBullet = true;
				}
				// If the button pressed is 'e', the FIGURE_BULLET_RIGHT moves to the right
				else if (iPress == 101 && iPosition != TAM - 1)
				{
					iPositionBullet = iPosition + 1;
					cWorld[iPositionBullet] = FIGURE_WORLD;
					cWorld[iPositionBullet] = FIGURE_BULLET_RIGHT;
					bBulletDirection = true;
					bBullet = true;
				}
			}
		}

		// If the bullet is in play and is in the first or last position of the world, the bullet is eliminated
		if (bBullet == true && (iPositionBullet == 0 || iPositionBullet == TAM - 1))
		{
			bBullet = false;
			if (bBulletDirection)
			{
				cWorld[TAM - 1] = FIGURE_WORLD;
			}
			else
			{
				cWorld[0] = FIGURE_WORLD;
			}
		}
		// If the bullet is in play and is not in the first or last position of the world, the bullet moves
		else if (bBullet == true && (iPositionBullet != 0 || iPositionBullet != TAM - 1))
		{
			if (bBulletDirection)
			{
				cWorld[iPositionBullet] = FIGURE_WORLD;
				iPositionBullet++;
				cWorld[iPositionBullet] = FIGURE_BULLET_RIGHT;
			}
			else
			{
				cWorld[iPositionBullet] = FIGURE_WORLD;
				iPositionBullet--;
				cWorld[iPositionBullet] = FIGURE_BULLET_LEFT;
			}
		}
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n%s", cWorld);
		Sleep(200);
	}

	getchar();
	return 0;
}