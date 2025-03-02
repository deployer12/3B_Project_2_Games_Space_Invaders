#include "alien.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> 

#define MAX_ALIENS 50
#define ALIEN_ROWS 5
#define ALIEN_COLS 10
#define MAX_BULLETS 10

struct Player {
    int x, y;
};

struct Alien {
    int x, y;
    int active;
};

struct Bullet {
    int x, y;
    int active;
};

int gameOver, score;
struct Player player;
struct Alien aliens[ALIEN_ROWS * ALIEN_COLS];
struct Bullet playerBullets[MAX_BULLETS];
int alienDir = 1;
int BLOCK_SIZE;
int shootCooldown = 0;

#define KEY_W 1
#define KEY_A 2
#define KEY_D 4
#define KEY_X 8

void drawAlien(int x, int y) {
    // Badan utama (elips hijau)
    drawEllipse(x, y, BLOCK_SIZE, BLOCK_SIZE, RGB(0, 255, 0));

    // Mata (elips putih besar)
    int eyeSize = BLOCK_SIZE / 2;
    int eyeX = x + BLOCK_SIZE / 4;
    int eyeY = y + BLOCK_SIZE / 4;
    drawEllipse(eyeX, eyeY, eyeSize, eyeSize, RGB(255, 255, 255));

    // Pupil (bentuk plus hitam di tengah mata)
    int pupilSize = eyeSize / 2;
    int pupilX = eyeX + eyeSize / 4;
    int pupilY = eyeY + eyeSize / 4;
    // Garis horizontal
    drawRect(pupilX, pupilY + pupilSize / 4, pupilSize, pupilSize / 4, RGB(0, 0, 0));
    // Garis vertikal
    drawRect(pupilX + pupilSize / 4, pupilY, pupilSize / 4, pupilSize, RGB(0, 0, 0));

    // Duri di sekeliling (8 arah)
    int spikeSize = BLOCK_SIZE / 4;
    int radius = BLOCK_SIZE / 2 + spikeSize / 2; 
    for (int i = 0; i < 8; i++) {
        float angle = i * (3.14159265 / 4); 
        int spikeX = x + BLOCK_SIZE / 2 + cos(angle) * radius - spikeSize / 2;
        int spikeY = y + BLOCK_SIZE / 2 + sin(angle) * radius - spikeSize / 2;
        drawRect(spikeX, spikeY, spikeSize, spikeSize, RGB(0, 255, 0));
    }
}

void setup() {
    gameOver = 0;
    score = 0;

    BLOCK_SIZE = WINDOW_HEIGHT / 40;

    player.x = WINDOW_WIDTH / 2 - BLOCK_SIZE / 2;
    player.y = WINDOW_HEIGHT - BLOCK_SIZE * 4;

    for (int row = 0; row < ALIEN_ROWS; row++) {
        for (int col = 0; col < ALIEN_COLS; col++) {
            int i = row * ALIEN_COLS + col;
            aliens[i].x = col * BLOCK_SIZE * 2 + WINDOW_WIDTH / 10;
            aliens[i].y = row * BLOCK_SIZE * 2 + WINDOW_HEIGHT / 10;
            aliens[i].active = 1;
        }
    }

    for (int i = 0; i < MAX_BULLETS; i++) {
        playerBullets[i].active = 0;
    }
    shootCooldown = 0;
    srand(time(0));
}

void draw() {
    clearScreen();

    drawRect(player.x, player.y, BLOCK_SIZE, BLOCK_SIZE, RGB(0, 255, 0));

    for (int i = 0; i < ALIEN_ROWS * ALIEN_COLS; i++) {
        if (aliens[i].active) {
            drawAlien(aliens[i].x, aliens[i].y);
        }
    }

    for (int i = 0; i < MAX_BULLETS; i++) {
        if (playerBullets[i].active) {
            drawRect(playerBullets[i].x, playerBullets[i].y, BLOCK_SIZE / 2, BLOCK_SIZE, RGB(255, 255, 0));
        }
    }

    updateScreen();
    Sleep(50);
}

void input() {
    int keys = getKeyInput();

    if (keys & KEY_A) {
        if (player.x > 0) player.x -= BLOCK_SIZE;
    }
    if (keys & KEY_D) {
        if (player.x < WINDOW_WIDTH - BLOCK_SIZE) player.x += BLOCK_SIZE;
    }
    if (keys & KEY_W && shootCooldown <= 0) {
        for (int i = 0; i < MAX_BULLETS; i++) {
            if (!playerBullets[i].active) {
                playerBullets[i].x = player.x + BLOCK_SIZE / 4;
                playerBullets[i].y = player.y - BLOCK_SIZE;
                playerBullets[i].active = 1;
                shootCooldown = 3;
                break;
            }
        }
    }
    if (keys & KEY_X) {
        gameOver = 1;
    }
}

void logic() {
    if (shootCooldown > 0) {
        shootCooldown--;
    }

    for (int i = 0; i < MAX_BULLETS; i++) {
        if (playerBullets[i].active) {
            playerBullets[i].y -= BLOCK_SIZE;
            if (playerBullets[i].y < 0) playerBullets[i].active = 0;

            for (int j = 0; j < ALIEN_ROWS * ALIEN_COLS; j++) {
                if (aliens[j].active) {
                    int bulletLeft = playerBullets[i].x;
                    int bulletRight = playerBullets[i].x + BLOCK_SIZE / 2;
                    int bulletTop = playerBullets[i].y;
                    int bulletBottom = playerBullets[i].y + BLOCK_SIZE;

                    int alienLeft = aliens[j].x;
                    int alienRight = aliens[j].x + BLOCK_SIZE;
                    int alienTop = aliens[j].y;
                    int alienBottom = aliens[j].y + BLOCK_SIZE;

                    if (bulletRight >= alienLeft && bulletLeft <= alienRight &&
                        bulletBottom >= alienTop && bulletTop <= alienBottom) {
                        aliens[j].active = 0;
                        playerBullets[i].active = 0;
                        score += 10;
                    }
                }
            }
        }
    }

    int moveDown = 0;
    for (int i = 0; i < ALIEN_ROWS * ALIEN_COLS; i++) {
        if (aliens[i].active) {
            aliens[i].x += alienDir * BLOCK_SIZE / 2;
            if (aliens[i].x <= 0 || aliens[i].x >= WINDOW_WIDTH - BLOCK_SIZE) {
                moveDown = 1;
            }
            if (aliens[i].y >= WINDOW_HEIGHT - BLOCK_SIZE) {
                gameOver = 1;
            }
        }
    }

    if (moveDown) {
        alienDir = -alienDir;
        for (int i = 0; i < ALIEN_ROWS * ALIEN_COLS; i++) {
            if (aliens[i].active) {
                aliens[i].y += BLOCK_SIZE;
            }
        }
    }

    int allDead = 1;
    for (int i = 0; i < ALIEN_ROWS * ALIEN_COLS; i++) {
        if (aliens[i].active) allDead = 0;
    }
    if (allDead) setup();
}

int main() {
    initWindow();
    setup();
    while (!gameOver) {
        draw();
        input();
        logic();
    }

    clearScreen();
    drawRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, RGB(255, 0, 0));
    updateScreen();
    Sleep(2000);

    return 0;
}