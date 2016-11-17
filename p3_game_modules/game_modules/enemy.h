// enemy.h
// Francisco Puertas Rodríguez
// fpuertasrodriguez@gmail.com

#ifndef __ENEMY_H__
#define __ENEMY_H__
#define FIGURE_ENEMY '*'

#include "world.h"

void initEnemy();
void autoMovementEnemy();
int getPositionEnemy();
void setPositionEnemy(int iNum);
void setEnemy(bool bUpdateEnemy);

#endif // !__ENEMY_H__