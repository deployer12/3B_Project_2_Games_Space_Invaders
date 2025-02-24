#include "mainmenu.h"
#include "graphics.h"

int main() {
<<<<<<< HEAD
    showMainMenu();
=======
    int gd = DETECT, gm;

    // Inisialisasi mode grafik
    initgraph(&gd, &gm, "C:\\MinGW\\lib");

    
    // Menggambar lingkaran di tengah layar
    circle(320, 240, 100);

    // Menunggu input sebelum keluar
    getch();
    closegraph();

>>>>>>> 6a904f982378d9354d6d85e1416f5cf689136cf7
    return 0;
}
