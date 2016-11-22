// enemy.h
// Francisco Puertas Rodríguez
// fpuertasrodriguez@gmail.com

#ifndef __ENEMY_H__
#define __ENEMY_H__
#define FIGURE_ENEMY '*'

#include "world.h"
#include <list>

class CEnemy
{
	public:
		CEnemy();
		~CEnemy();
		void autoMovementEnemy();
		int getPositionEnemy();
		void setPositionEnemy(int iNum);
		void setEnemy(bool bUpdateEnemy);

	private:
		int iPositionEnemy = -1;
		bool bEnemy = true;
};

extern std::list<CEnemy> lEnemy;

void createEnemy();

#endif // !__ENEMY_H__