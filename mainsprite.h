#ifndef MAINSPRITE_H
#define MAINSPRITE_H


typedef struct
{
    int x, y;
}Player;

typedef struct
{
    int x, y;
}Bullets_Player;

void MovePlayer(Player *Player);
void MoveBullets(Bullets_Player *Bullets_Player);
void drawSpaceship(int x, int y);






#endif