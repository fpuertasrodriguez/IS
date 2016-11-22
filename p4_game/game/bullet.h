// bullet.h
// Francisco Puertas Rodríguez
// fpuertasrodriguez@gmail.com

#ifndef __BULLET_H__
#define __BULLET_H__
#define FIGURE_BULLET_LEFT '<'
#define FIGURE_BULLET_RIGHT '>'

#include "world.h"
#include "human.h"
#include <list>

class CBullet
{
	public:
		CBullet();
		~CBullet();
		void setBullet(bool bUpdateBullet);
		bool getBullet();
		void autoMovementBullet();
		void setPositionBullet(unsigned int uNum);
		unsigned int getPositionBullet();
		void setDirectionBullet(bool bDirection);
		bool getDirectionBullet();

	private:
		bool bBullet = false;
		bool bDirectionBullet = false;
		unsigned int uPositionBullet;
};

extern std::list<CBullet> lBullet;

void createBullet(unsigned int uBottonPress);

#endif // !__BULLET_H__