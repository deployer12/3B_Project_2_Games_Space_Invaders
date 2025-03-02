#include <graphics.h>
#include "mainsprite.c"
#include <conio.h>
#include <windows.h>

int main() {
    Player Spaceship;

    DWORD screenwidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenheight = GetSystemMetrics(SM_CXSCREEN);

    initwindow(screenwidth, screenheight, "");  
    Spaceship.x_Player = (int)screenwidth / 2;
    
    
    //Karakter Utama 
    SpaceshipMove(&Spaceship, screenheight / 2);



    getch();
    closegraph();

    return 0;
}