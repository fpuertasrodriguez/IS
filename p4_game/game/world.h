// world.h
// Francisco Puertas Rodríguez
// fpuertasrodriguez@gmail.com

#ifndef __WORLD_H__
#define __WORLD_H__
#define TAM_WORLD 101
#define FIGURE_WORLD '_'

#include "bullet.h"
#include "enemy.h"
#include "weather.h"

void initWorld();
void printWorld();
void updateWorld(char cFigure, unsigned int uPosition);
void updateScore(unsigned int uUpdateScore);
unsigned int getScore();
void movementInWorld(char cFigure, unsigned int & uPosition, bool direction);
bool updateWorld();

#endif // !__WORLD_H__