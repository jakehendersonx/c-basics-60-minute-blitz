#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define GRID_SIZE 10

int getch(void) {
    int ch;
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

int main() {
    char grid[GRID_SIZE][GRID_SIZE];
    int x = 0, y = 0;

    // Initialize the grid with '0' characters
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '0';
        }
    }

    while (1) {
        // Clear the screen
        printf("\033[2J\033[1;1H");

        // Print the grid
        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                if (i == y && j == x) {
                    printf("\033[1;30;46m%c\033[0m", grid[i][j]);
                } else {
                    printf("%c", grid[i][j]);
                }
            }
            printf("\n");
        }

        // Get user input
        int ch = getch();

        // Handle arrow key input
        switch (ch) {
            case 65: // Up arrow
                y = (y - 1 + GRID_SIZE) % GRID_SIZE;
                break;
            case 66: // Down arrow
                y = (y + 1) % GRID_SIZE;
                break;
            case 67: // Right arrow
                x = (x + 1) % GRID_SIZE;
                break;
            case 68: // Left arrow
                x = (x - 1 + GRID_SIZE) % GRID_SIZE;
                break;
            case 32: // Spacebar
                printf("Enter new character: ");
                char newchar = getchar();
                grid[y][x] = newchar;
                break;
        }
    }

    return 0;
}