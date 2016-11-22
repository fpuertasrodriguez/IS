// weather.cpp
// Francisco Puertas Rodríguez
// fpuertasrodriguez@gmail.com

#include "stdafx.h"
#include "weather.h"

static unsigned int uNumRain = TAM_WORLD / 15;
static unsigned int iRainMode[TAM_WORLD / 15];
static unsigned int iPositionRain[TAM_WORLD / 15];
static bool bRainActive[TAM_WORLD / 15];

void updateWeather()
{
	for (unsigned int i = 0; i < uNumRain; i++)
	{
		if (iRainMode[i] == 0)
		{
			iPositionRain[i] = rand() % TAM_WORLD;

			if (abs(static_cast<int>(oHuman.getPositionHuman() - iPositionRain[i])) > 3)
			{
				iRainMode[i] = 1;
				oWorld.updateWorld(FIGURE_RAIN_BEGIN, iPositionRain[i]);
			}
		}
		else if (iRainMode[i] == 1)
		{
			oWorld.updateWorld(FIGURE_RAIN_INTERMEDIATE, iPositionRain[i]);
			iRainMode[i] = 2;
		}
		else if (iRainMode[i] == 2)
		{
			oWorld.updateWorld(FIGURE_RAIN_END, iPositionRain[i]);
			iRainMode[i] = 3;
		}
		else if (iRainMode[i] == 3)
		{
			oWorld.updateWorld(FIGURE_WORLD, iPositionRain[i]);
			iRainMode[i] = 0;
		}
	}
}