// world_enemy.cpp 
// Francisco Puertas Rodriguez
// fpuertasrodriguez@gmail.com

#include "stdafx.h"
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 51
#define FIGURE_HUMAN '-'
#define FIGURE_WORLD '_'
#define FIGURE_BULLET_LEFT '<'
#define FIGURE_BULLET_RIGHT '>'
#define FIGURE_ENEMY 'E'

int main()
{
	// Variable declaration 
	// World
	char cWorld[TAM + 1];

	// Human
	unsigned int  iPosition = TAM / 2;
	bool bHealth = true;
	unsigned int score = 0;

	// Bullet
	unsigned int  iPositionBullet;
	bool bBullet = false;
	bool bBulletDirection = false;

	// Button
	unsigned int  iPress;

	// Enemy
	int iPositionEnemy = -1;
	bool bEnemy = true;

	srand(static_cast<unsigned int>(time(NULL)));

	// Initialization of the world
	for (unsigned int i = 0; i < TAM; i++)
	{
		cWorld[i] = FIGURE_WORLD;
	}
	
	cWorld[TAM] = '\0';
	cWorld[iPosition] = FIGURE_HUMAN;
	
	printf("\n\n\n\n\n\n\n\n\n\n%s", cWorld);

	// Game loop
	while (bHealth)
	{
		if (_kbhit())
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

			// Kill to the enemy
			if (abs(static_cast<int>(iPositionEnemy - iPositionBullet)) <= 1)
			{
				cWorld[iPositionBullet] = FIGURE_WORLD;
				cWorld[iPositionEnemy] = FIGURE_WORLD;
				iPositionEnemy = -1;
				bBullet = false;
				bEnemy = true;
				iPositionBullet = TAM-1;
				++score;
			}
		}
		
		// Initialization of the enemy
		if (iPositionEnemy == -1)
		{
			iPositionEnemy = rand() % 2;

			if (iPositionEnemy == 1)
			{
				iPositionEnemy = TAM - 1;
				bEnemy = false;
			}

			cWorld[iPositionEnemy] = FIGURE_ENEMY;
		}
		// Movement os the enemy
		else if (((iPositionEnemy != 0 || bEnemy) && (iPositionEnemy != TAM - 1 || !bEnemy)))
		{
			if (bEnemy)
			{
				cWorld[iPositionEnemy] = FIGURE_WORLD;
				++iPositionEnemy;
				cWorld[iPositionEnemy] = FIGURE_ENEMY;
			}
			else if (iPositionEnemy != 0)
			{
				cWorld[iPositionEnemy] = FIGURE_WORLD;
				--iPositionEnemy;
				cWorld[iPositionEnemy] = FIGURE_ENEMY;
			}
		}
		
		// Game Over
		if (iPosition == iPositionEnemy)
		{
			bHealth = false;
		}

		system("cls");
		printf("\n\nScore: %d\n\n\n\n\n\n\n\n%s", score, cWorld);
		Sleep(50);
	}

	system("cls");
	printf("\nGAME OVER\n");
	printf("\nScore: %d\n", score);
	getchar();

	return 0;
}