#ifndef MAINSPRITE_H
#define MAINSPRITE_H
#include <graphics.h>
#include <conio.h>
#include <windows.h>


typedef struct
{
    int X_Player, Y_Player;
}Player;



void MoveBullets(Player *player);
void SpaceshipMove(Player *player);
void DrawSpaceShip(Player *player);
void SpaceShip(Player *player);





#endif