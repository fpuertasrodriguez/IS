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

class CWorld
{
	public:
		CWorld();
		~CWorld();
		void printWorld();
		void updateWorld(char cFigure, unsigned int uPosition);
		void updateScore(unsigned int uUpdateScore);
		unsigned int getScore();
		void movementInWorld(char cFigure, unsigned int & uPosition, bool direction);
		bool updateWorld();

	private:
		char cWorld[TAM_WORLD + 1];
		unsigned int uScore;
};

extern class CWorld oWorld;

#endif // !__WORLD_H__