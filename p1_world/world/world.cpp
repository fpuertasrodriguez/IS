// mundo.cpp 
//

#include "stdafx.h"
#include <conio.h>

#define TAM 21
#define FIGURE_HUMAN '-'
#define FIGURE_WORLD '_'
#define FIGURE_BULLET_LEFT '<'
#define FIGURE_BULLET_RIGHT '>'

int main()
{
	char cWorld[TAM + 1];
	int  iPosition = TAM / 2;
	int  iPositionBullet;
	bool bBullet = false;
	int  iPress;
	bool bBulletDirection = false; // false == left , true == right

	for (unsigned int i = 0 ; i < TAM ; i++)
	{
		cWorld[i] = FIGURE_WORLD;
	}
	cWorld[iPosition] = FIGURE_HUMAN;
	cWorld[TAM] = '\0';

	printf("\n\n\n\n\n\n\n\n\n\n%s", cWorld);

	while (1)
	{
		if (_kbhit())
		{
			iPress = _getch();
			if (iPress == 97 && iPosition != 0) // a
			{
				cWorld[iPosition] = FIGURE_WORLD;
				iPosition--;
				cWorld[iPosition] = FIGURE_HUMAN;
			}
			else if (iPress == 100 && iPosition != TAM - 1) // d
			{
				cWorld[iPosition] = FIGURE_WORLD;
				iPosition++;
				cWorld[iPosition] = FIGURE_HUMAN;
			}

			if (!bBullet)
			{
				if (iPress == 113 && iPosition != 0) // q
				{
					iPositionBullet = iPosition - 1;
					cWorld[iPositionBullet] = FIGURE_WORLD;
					cWorld[iPositionBullet] = FIGURE_BULLET_LEFT;
					bBulletDirection = false;
					bBullet = true;
				}
				else if (iPress == 101 && iPosition != TAM - 1) // e
				{
					iPositionBullet = iPosition + 1;
					cWorld[iPositionBullet] = FIGURE_WORLD;
					cWorld[iPositionBullet] = FIGURE_BULLET_RIGHT;
					bBulletDirection = true;
					bBullet = true;
				}
			}
		}
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

