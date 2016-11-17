// check_interactions.h
// Francisco Puertas Rodr�guez
// fpuertasrodriguez@gmail.com

#ifndef __CHECK_INTERACTIONS__
#define __CHECK_INTERACTIONS__

#include "world.h"
#include "human.h"
#include "enemy.h"
#include "bullet.h"

void checkKillEnemy(CBullet & oBullet, CEnemy & oEnemy);
bool checkDeath(CEnemy & oEnemy);

#endif // !__CHECK_INTERACTIONS__