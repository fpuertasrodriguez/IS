// weather.h
// Francisco Puertas Rodríguez
// fpuertasrodriguez@gmail.com

#ifndef __WEATHER_H__
#define __WEATHER_H__

#include "world.h"
#include "bullet.h"
#include "enemy.h"
#include "human.h"

#define FIGURE_RAIN_BEGIN '\''
#define FIGURE_RAIN_INTERMEDIATE '|'
#define FIGURE_RAIN_END '.'

void updateWeather();

#endif // !__WEATHER_H__
