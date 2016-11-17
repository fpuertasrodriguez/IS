// bullet.h
// Francisco Puertas Rodríguez
// fpuertasrodriguez@gmail.com

#ifndef __BULLET_H__
#define __BULLET_H__
#define FIGURE_BULLET_LEFT '<'
#define FIGURE_BULLET_RIGHT '>'

#include "world.h"
#include "human.h"

void shootBullet(int iBottonPress);
void setBullet(bool bUpdateBullet);
bool getBullet();
void autoMovementBullet();
void setPositionBullet(int iNum);
unsigned int getPositionBullet();

#endif // !__BULLET_H__