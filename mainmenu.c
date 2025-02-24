#include "mainmenu.h"

void drawText(const char *text, int x, int y, int color) {
    setcolor(color);
    outtextxy(x, y, text);
}

void drawButton(const char *label, int x, int y, int width, int height, int color) {
    setcolor(color);
    rectangle(x, y, x + width, y + height);
    drawText(label, x + (width / 4), y + (height / 4), color);
}

void showMainMenu() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Set latar belakang hitam
    setbkcolor(BLACK);
    cleardevice();

    // Judul game
    setcolor(GREEN);
    drawText("SPACE ALIEN", 200, 100, GREEN);
    drawText("INVADERS", 260, 150, RED);

    // Gambar tombol Play
    drawButton("PLAY", 250, 250, 100, 50, GREEN);

    getch(); // Tunggu input sebelum keluar
    closegraph()nn;
}
