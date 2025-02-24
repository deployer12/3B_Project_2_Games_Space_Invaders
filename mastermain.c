#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;

    // Inisialisasi mode grafik
    initgraph(&gd, &gm, "C:\\MinGW\\lib");

    // Menggambar lingkaran di tengah layar
    circle(320, 240, 100);

    // Menunggu input sebelum keluar
    getch();
    closegraph();

    return 0;
}
