// bullet.h
// Francisco Puertas Rodríguez
// fpuertasrodriguez@gmail.com

#ifndef __BULLET_H__
#define __BULLET_H__

#include "world.h"
#include "human.h"

#define FIGURE_BULLET_LEFT '<'
#define FIGURE_BULLET_RIGHT '>'

void shootBullet(int iBottonPress);
void setBullet(bool bUpdateBullet);
bool getBullet();
void autoMovementBullet();
void setPositionBullet(int iNum);
unsigned int getPositionBullet();

#endif // !__BULLET_H__
