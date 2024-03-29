#include <stdio.h>
#include <unistd.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 24
#define WAVE_FRAMES 10

char screen[SCREEN_HEIGHT][SCREEN_WIDTH];

void clear_screen() {
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            screen[y][x] = ' ';
        }
    }
}

void draw_beach() {
    for (int x = 0; x < SCREEN_WIDTH; x++) {
        screen[SCREEN_HEIGHT - 1][x] = '~';
    }
    for (int y = SCREEN_HEIGHT - 2; y >= SCREEN_HEIGHT - 5; y--) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            screen[y][x] = ',';
        }
    }
}

void draw_wave(int frame) {
    int wave_height = (frame < WAVE_FRAMES / 2) ? frame : WAVE_FRAMES - frame;
    for (int x = 0; x < SCREEN_WIDTH; x++) {
        int wave_x = x - (SCREEN_WIDTH / 2) + (frame * 2);
        if (wave_x >= 0 && wave_x < SCREEN_WIDTH) {
            screen[SCREEN_HEIGHT - 1 - wave_height][wave_x] = '~';
        }
    }
}

int main() {
    while (1) {
        for (int frame = 0; frame < WAVE_FRAMES; frame++) {
            clear_screen();
            draw_beach();
            draw_wave(frame);

            for (int y = 0; y < SCREEN_HEIGHT; y++) {
                for (int x = 0; x < SCREEN_WIDTH; x++) {
                    printf("%c", screen[y][x]);
                }
                printf("\n");
            }
            printf("\033[%dA", SCREEN_HEIGHT); // Move cursor up SCREEN_HEIGHT lines
            usleep(100000); // Pause for 100ms
        }
    }
    return 0;
}