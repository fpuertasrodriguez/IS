// game_modules.cpp
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

	initWorld();
	initHuman();
	
	srand(static_cast<unsigned int>(time(NULL)));

	while (bGame)
	{
		initEnemy();

		if (_kbhit())
		{
			iPress = _getch();

			if (iPress == 97 || iPress == 100)
			{
				movementHuman(iPress);
			}
			else if (iPress == 113 || iPress == 101)
			{
				shootBullet(iPress);
			}
		}

		updateWeather();
		autoMovementBullet();
		autoMovementEnemy();

		bGame = checkDeath();

		checkKillEnemy();
		
		Sleep(50);
		system("cls");
		printf("Score: %d", getScore());
		printWorld();	
	}

	system("cls");
	printf("Game Over\nYour score is: %d", getScore());
	getchar();

    return 0;
}

