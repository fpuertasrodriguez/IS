// check_interactions.h
// Francisco Puertas Rodríguez
// fpuertasrodriguez@gmail.com

#ifndef __CHECK_INTERACTIONS__
#define __CHECK_INTERACTIONS__

#include "world.h"
#include "human.h"
#include "enemy.h"
#include "bullet.h"

void checkKillEnemy(std::list<CBullet>::iterator oBullet, std::list<CEnemy>::iterator oEnemy);
bool checkDeath(CEnemy oEnemy);
void updateList();

#endif // !__CHECK_INTERACTIONS__