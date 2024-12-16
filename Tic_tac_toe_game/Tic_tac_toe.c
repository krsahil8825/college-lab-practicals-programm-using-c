#include <stdio.h>
#include <conio.h>

char board[3][3] = {{'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'}};

int checkWin();
void printBoard();
void markMove(int, char);

void main() {
    int player = 1, choice, row, col;
    char mark;

    // Loop until there is a winner or tie
    while(1) {
        printBoard();
        
        // Switch between player 1 and player 2
        player = (player % 2) ? 1 : 2;
        mark = (player == 1) ? 'X' : 'O';
        
        // Ask for player input
        printf("Player %d, enter the number where you want to place your %c: ", player, mark);
        scanf("%d", &choice);
        
        // Check if the position is valid
        if (choice < 1 || choice > 9) {
            printf("Invalid move! Please try again.\n");
            continue;
        }

        // Calculate row and column from choice
        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        // Check if the cell is already taken
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            printf("The cell is already occupied. Try again.\n");
            continue;
        }

        // Mark the move on the board
        markMove(choice, mark);

        // Check if any player has won
        if (checkWin()) {
            printBoard();
            printf("Player %d wins!\n", player);
            break;
        }

        // Check if the board is full (tie condition)
        int tie = 1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != 'X' && board[i][j] != 'O') {
                    tie = 0;
                    break;
                }
            }
        }
        if (tie) {
            printBoard();
            printf("It's a tie!\n");
            break;
        }

        // Switch to the next player
        player++;
    }
    
    getch();  // Wait for the user to press a key before closing the program
}

// Function to print the Tic-Tac-Toe board
void printBoard() {
    printf("\nTic-Tac-Toe Board:\n\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

// Function to mark a player's move on the board
void markMove(int choice, char mark) {
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;
    board[row][col] = mark;
}

// Function to check if any player has won
int checkWin() {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;
    
    return 0;
}
