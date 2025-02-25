#include <graphics.h>
#include <conio.h>
#include <windows.h>
#include <iostream>


int main() {
    

    DWORD screenwidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenheight = GetSystemMetrics(SM_CXSCREEN);



    getch();
    closegraph();

    return 0;
}
