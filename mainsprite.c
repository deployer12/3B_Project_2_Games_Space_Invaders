#include <graphics.h>
#include "mainsprite.h"



void drawSpaceship(Player *player) {
    int x = player->X_Player;
    int y = player->Y_Player;

    // Warna utama badan kapal
    setcolor(CYAN);
    setfillstyle(SOLID_FILL, CYAN);
    int body[] = {x, y, x - 20, y + 40, x + 20, y + 40, x, y};
    fillpoly(4, body);

    // Kokpit
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    fillellipse(x, y + 10, 7, 10);

    // Sayap kiri
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    int leftWing[] = {x - 20, y + 40, x - 40, y + 60, x - 20, y + 60, x - 20, y + 40};
    fillpoly(4, leftWing);

    // Sayap kanan
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    int rightWing[] = {x + 20, y + 40, x + 40, y + 60, x + 20, y + 60, x + 20, y + 40};
    fillpoly(4, rightWing);

    // Mesin
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    bar(x - 10, y + 40, x + 10, y + 50);

    // Cahaya mesin (api thruster)
    setcolor(LIGHTBLUE);
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    int thruster[] = {x - 5, y + 50, x + 5, y + 50, x, y + 70, x - 5, y + 50};
    fillpoly(4, thruster);
}

void SpaceshipMove(Player *player) { // Added void return type
    if (kbhit()) {
        char key = getch();
        if (key == 'a' && player->X_Player > 40) {
            player->X_Player -= 10;
        } else if (key == 'd' && player->X_Player < getmaxx() - 40) {
            player->X_Player += 10;
        }
    }
}

void SpaceShip(Player *player) {
    int buffer = imagesize(0, 0, getmaxx(), getmaxy());
    void *frameBuffer = malloc(buffer);
    
    
    while (1) {
        getimage(0, 0, getmaxx(), getmaxy(), frameBuffer);
            if (kbhit()) {
                char key = getch();
                if (key == 27) { 
                    break; 
                }
            }
            cleardevice();
            SpaceshipMove(player);
            drawSpaceship(player);
            
        }
    }
    