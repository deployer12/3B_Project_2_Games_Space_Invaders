#include <graphics.h>
#include <conio.h>
#include <vector>

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 400
#define PLAYER_SPEED 10
#define BULLET_SPEED 10
#define ALIEN_ROWS 3
#define ALIEN_COLS 6
#define ALIEN_SIZE 20

struct Bullet {
    int x, y;
    bool active;
};

struct Alien {
    int x, y;
    bool alive;
};

int playerX = SCREEN_WIDTH / 2;
int playerY = SCREEN_HEIGHT - 50;
std::vector<Bullet> bullets;
std::vector<Alien> aliens;
int alienDir = 1; // 1 ke kanan, -1 ke kiri

void drawPlayer() {
    setfillstyle(SOLID_FILL, WHITE);
    bar(playerX - 20, playerY, playerX + 20, playerY + 10);
    bar(playerX - 10, playerY - 10, playerX + 10, playerY);
}

void drawBullets() {
    setfillstyle(SOLID_FILL, RED);
    for (auto &bullet : bullets) {
        if (bullet.active) {
            bar(bullet.x - 2, bullet.y, bullet.x + 2, bullet.y - 10);
        }
    }
}

void drawAliens() {
    setfillstyle(SOLID_FILL, GREEN);
    for (auto &alien : aliens) {
        if (alien.alive) {
            bar(alien.x, alien.y, alien.x + ALIEN_SIZE, alien.y + ALIEN_SIZE);
        }
    }
}

void moveBullets() {
    for (auto &bullet : bullets) {
        if (bullet.active) {
            bullet.y -= BULLET_SPEED;
            if (bullet.y < 0) bullet.active = false;
        }
    }
}

void moveAliens() {
    bool moveDown = false;
    for (auto &alien : aliens) {
        if (alien.alive) {
            alien.x += alienDir * 5;
            if (alien.x <= 0 || alien.x + ALIEN_SIZE >= SCREEN_WIDTH) {
                moveDown = true;
            }
        }
    }
    if (moveDown) {
        alienDir *= -1;
        for (auto &alien : aliens) {
            alien.y += 10;
        }
    }
}

void checkCollisions() {
    for (auto &bullet : bullets) {
        if (!bullet.active) continue;
        for (auto &alien : aliens) {
            if (alien.alive && bullet.x > alien.x && bullet.x < alien.x + ALIEN_SIZE &&
                bullet.y > alien.y && bullet.y < alien.y + ALIEN_SIZE) {
                alien.alive = false;
                bullet.active = false;
                break;
            }
        }
    }
}

void initAliens() {
    for (int i = 0; i < ALIEN_ROWS; i++) {
        for (int j = 0; j < ALIEN_COLS; j++) {
            aliens.push_back({j * (ALIEN_SIZE + 10) + 50, i * (ALIEN_SIZE + 10) + 50, true});
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    initAliens();

    while (true) {
        cleardevice();
        drawPlayer();
        drawBullets();
        drawAliens();
        moveBullets();
        moveAliens();
        checkCollisions();

        if (kbhit()) {
            char key = getch();
            if (key == 75 && playerX > 20) { // Panah kiri
                playerX -= PLAYER_SPEED;
            } else if (key == 77 && playerX < SCREEN_WIDTH - 20) { // Panah kanan
                playerX += PLAYER_SPEED;
            } else if (key == 32) { // Tombol spasi untuk menembak
                bullets.push_back({playerX, playerY - 10, true});
            }
        }
        
        delay(50);
    }

    closegraph();
    return 0;
}
