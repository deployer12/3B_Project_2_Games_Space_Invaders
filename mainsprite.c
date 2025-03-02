#include <graphics.h>
void drawSpaceship(int x, int y) {
    setcolor(WHITE);
    
    // Badan utama
    line(x, y, x - 20, y + 40);
    line(x, y, x + 20, y + 40);
    line(x - 20, y + 40, x + 20, y + 40);
    
    // Sayap kiri
    line(x - 20, y + 40, x - 40, y + 60);
    line(x - 40, y + 60, x - 20, y + 60);
    
    // Sayap kanan
    line(x + 20, y + 40, x + 40, y + 60);
    line(x + 40, y + 60, x + 20, y + 60);
    
    // Mesin
    line(x - 10, y + 40, x - 10, y + 50);
    line(x + 10, y + 40, x + 10, y + 50);
    
    // Cahaya mesin
    setcolor(LIGHTBLUE);
    line(x - 5, y + 50, x, y + 60);
    line(x + 5, y + 50, x, y + 60);
}