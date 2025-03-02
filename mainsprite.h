#ifndef MAINSPRITE_H
#define MAINSPRITE_H
#include <graphics.h>
#include <conio.h>
#include <windows.h>


typedef struct
{
    int x_Player, y_player;
}Player;



void MoveBullets(Player *player);
void SpaceshipMove(Player *player);
void DrawSpaceShip(Player *player, int);






#endif