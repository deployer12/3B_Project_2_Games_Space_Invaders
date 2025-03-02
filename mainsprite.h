#ifndef MAINSPRITE_H
#define MAINSPRITE_H


typedef struct
{
    int x_Player, y_player;
}Player;

void MoveBullets(Player *player);
void SpaceshipMove(Player *player, int y);






#endif