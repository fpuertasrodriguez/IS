// human.h
// Francisco Puertas Rodríguez
// fpuertasrodriguez@gmail.com

#ifndef __HUMAN_H__
#define __HUMAN_H__
#define FIGURE_HUMAN '-'

#include "world.h"

class CHuman
{
	public:
		CHuman();
		~CHuman();
		//void initHuman();
		void movementHuman(unsigned int uBottonPress);
		unsigned int getPositionHuman();

	private:
		unsigned int uPositionHuman;
};

extern class CHuman oHuman;

#endif // !__HUMAN_H__