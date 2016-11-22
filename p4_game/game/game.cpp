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
	unsigned int uPress;
	unsigned int uRespawnTime = TAM_WORLD / 2;
	unsigned int uRechargeTime = 0;

	srand(static_cast<unsigned int>(time(NULL)));

	while (bGame)
	{
		if (uRespawnTime >= TAM_WORLD / 8)
		{
			uRespawnTime = 0;
			createEnemy();
		}
			
		if (_kbhit())
		{
			uPress = _getch();

			if (uPress == 97 || uPress == 100)
			{
				oHuman.movementHuman(uPress);
			}
			else if (uPress == 113 || uPress == 101)
			{
				if (uRechargeTime > 5)
				{
					uRechargeTime = 0;
					createBullet(uPress);
				}
			}
		}

		bGame = oWorld.updateWorld();

		Sleep(50);
		system("cls");
		printf("Score: %d", oWorld.getScore());
		oWorld.printWorld();

		++uRechargeTime;
		++uRespawnTime;
	}

	lEnemy.clear();
	lBullet.clear();

	system("cls");
	printf("Game Over\nYour score is: %d\nPress enter to exit...", oWorld.getScore());
	getchar();

	return 0;
}