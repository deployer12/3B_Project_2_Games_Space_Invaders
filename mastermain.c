#include <graphics.h>
#include "mainsprite.c"
#include <conio.h>
#include <windows.h>



int main() {
    

    DWORD screenwidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenheight = GetSystemMetrics(SM_CXSCREEN);

    initwindow(screenwidth, screenheight, "");  
      
    drawSpaceship(screenwidth / 2, screenheight / 2);



    getch();
    closegraph();

    return 0;
}
