// world.h
// Francisco Puertas Rodríguez
// fpuertasrodriguez@gmail.com

#ifndef __WORLD_H__
#define __WORLD_H__

#define TAM_WORLD 51
#define FIGURE_WORLD '_'

void initWorld();
void printWorld();
void updateWorld(char cFigure, unsigned int iPosition);
void updateScore(int iUpdateScore);
int getScore();
void movementInWorld(char cFigure, unsigned int & iPosition, bool direction);

#endif // !__WORLD_H__