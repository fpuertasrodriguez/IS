// game.cpp
// Francisco Puertas Rodríguez
// fpuertasrodriguez@gmail.com

#include "stdafx.h"
#include "world.h"
#include "human.h"
#include "bullet.h"
#include "enemy.h"
#include "check_interactions.h"
#include "weather.h"

int main()
{
	// Variable declaration 
	bool bGame = true;
	unsigned int iPress;
	CBullet oBullet;
	CEnemy oEnemy;

	initWorld();
	initHuman();

	srand(static_cast<unsigned int>(time(NULL)));

	while (bGame)
	{
		oEnemy.initEnemy();

		if (_kbhit())
		{
			iPress = _getch();

			if (iPress == 97 || iPress == 100)
			{
				movementHuman(iPress);
			}
			else if (iPress == 113 || iPress == 101)
			{
				oBullet.shootBullet(iPress);
			}
		}

		updateWeather();
		oBullet.autoMovementBullet();
		oEnemy.autoMovementEnemy();

		bGame = checkDeath(oEnemy);

		checkKillEnemy(oBullet, oEnemy);

		Sleep(50);
		system("cls");
		printf("Score: %d", getScore());
		printWorld();
	}

	system("cls");
	printf("Game Over\nYour score is: %d\nPress enter to exit...", getScore());
	getchar();

	return 0;
}