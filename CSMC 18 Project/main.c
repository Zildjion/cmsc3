#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define ROWS 10
#define COLS 5
#define CELL_WIDTH 16

// Data structure to hold cell content
char spreadsheet[ROWS][COLS][CELL_WIDTH];

// Clear the screen and move the cursor to the top-left
void clear_screen() {
    system("cls");
}

// Draw the spreadsheet grid
void draw_grid(int current_row, int current_col) {
    clear_screen();
    printf("Simple TUI Spreadsheet\n\n");
    for (int i = 0; i <= ROWS; i++) {
        for (int j = 0; j <= COLS; j++) {
            // Draw corners, vertical, and horizontal lines
            if (i == 0) {
                if (j == 0) printf("┌");
                else if (j == COLS) printf("┐");
                else printf("┬");
            } else if (i == ROWS) {
                if (j == 0) printf("└");
                else if (j == COLS) printf("┘");
                else printf("┴");
            } else {
                if (j == 0) printf("├");
                else if (j == COLS) printf("┤");
                else printf("┼");
            }

            if (j < COLS) {
                for (int k = 0; k < CELL_WIDTH; k++) printf("─");
            }
        }
        printf("\n");

        if (i < ROWS) {
            for (int j = 0; j <= COLS; j++) {
                if (j == 0) printf("│");
                else if (j == COLS) printf("│");
                else printf("│");

                if (j < COLS) {
                    // Print cell contents
                    if (i == current_row && j == current_col)
                        printf("\033[7m%-*s\033[0m", CELL_WIDTH, spreadsheet[i][j]); // Highlight current cell
                    else
                        printf("%-*s", CELL_WIDTH, spreadsheet[i][j]);
                }
            }
            printf("\n");
        }
    }
}

// Main interactive loop
void run_spreadsheet() {
    int row = 0, col = 0;
    int key;

    draw_grid(row, col);

    while (1) {
        key = getch();

        switch (key) {
            case 'q': // Quit the program
                return;
            case 72: // Up arrow key
                if (row > 0) row--;
                break;
            case 80: // Down arrow key
                if (row < ROWS - 1) row++;
                break;
            case 75: // Left arrow key
                if (col > 0) col--;
                break;
            case 77: // Right arrow key
                if (col < COLS - 1) col++;
                break;
            case 'w': // Up arrow key
                if (row > 0) row--;
                break;
            case 's': // Down arrow key
                if (row < ROWS - 1) row++;
                break;
            case 'a': // Left arrow key
                if (col > 0) col--;
                break;
            case 'd': // Right arrow key
                if (col < COLS - 1) col++;
            case 'W': // Up arrow key
                if (row > 0) row--;
                break;
            case 'S': // Down arrow key
                if (row < ROWS - 1) row++;
                break;
            case 'A': // Left arrow key
                if (col > 0) col--;
                break;
            case 'D': // Right arrow key
                if (col < COLS - 1) col++;
                break;
            case '\r': // Enter key to edit cell
                printf("Enter value for cell (%d, %d): ", row, col);
                fgets(spreadsheet[row][col], CELL_WIDTH, stdin);
                spreadsheet[row][col][strcspn(spreadsheet[row][col], "\n")] = '\0'; // Remove newline
                break;
        }
        draw_grid(row, col);
    }
}

int main() {
    SetConsoleOutputCP(65001);
    run_spreadsheet();
    return 0;
}
