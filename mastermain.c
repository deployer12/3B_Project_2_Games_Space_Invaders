#include <graphics.h>
#include "mainsprite.h"
#include "mainmenu.h"
#include <conio.h>
#include <windows.h>




int main() {
    Player Spaceship;
    
    
    showMainMenu();
    Spaceship.x_Player = getmaxx() / 2;
    DrawSpaceShip(&Spaceship, getmaxx() / 2);



    getch();
    closegraph();
}