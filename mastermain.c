#include <graphics.h>
#include "mainsprite.h"
#include "mainmenu.h"
#include <conio.h>
#include <windows.h>




int main() {
    Player Spaceship;
    DWORD screenwidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenheight = GetSystemMetrics(SM_CXSCREEN);

    
      
    Spaceship.x_Player = (int)screenwidth / 2;
    
    
    showMainMenu();
    SpaceshipMove(&Spaceship, screenheight / 2);



    getch();
    closegraph();
}