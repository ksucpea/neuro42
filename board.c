#include <stdio.h>
#include "board.h"

/* displays the tic tac toe board */
/* utilizes the passed in state to generate the rows and columns to display */
void displayBoard(struct BoardState state) {
    char line[] = "   |   |   ";
    char const *spaceBetween = "              ";
    char const *rowLine = "---+---+---";
    int i;
    printf("Current Board:           Coordinates:\n");

    for(i = 0; i < 3; i++) {
        line[(i * 4) + 1] = state.tiles[i] == X_TILE ? 'X' : state.tiles[i] == O_TILE ? 'O' : ' ';
    }
    printf("%s%s 1 | 2 | 3\n", line, spaceBetween);
    printf("%s%s%s\n", rowLine, spaceBetween, rowLine);
    
    for(i = 0; i < 3; i++) {
        line[(i * 4) + 1] = state.tiles[i + 3] == X_TILE ? 'X' : state.tiles[i + 3] == O_TILE ? 'O' : ' ';
    }
    printf("%s%s 4 | 5 | 6\n", line, spaceBetween);
    printf("%s%s%s\n", rowLine, spaceBetween, rowLine);
    for(i = 0; i < 3; i++) {
        line[(i * 4) + 1] = state.tiles[i + 6] == X_TILE ? 'X' : state.tiles[i + 6] == O_TILE ? 'O' : ' ';
    }
    printf("%s%s 7 | 8 | 9\n", line, spaceBetween);

}

/* checks the player state for a winning state */
/* returns -1 if no one has won, 1 (X_TILE) if player X wins, and 2 (O_TILE) if player O wins */
int checkWin(struct BoardState state) {
    int *t = state.tiles;
    /* checking rows and columns */
    for(int i = 0; i < 3; i++) {
        if (t[i * 3] != EMPTY_TILE && t[i * 3] == t[(i * 3) + 1] && t[(i * 3) + 1] == t[(i * 3) + 2]) return t[i * 3];
        if (t[i] != EMPTY_TILE && t[i] == t[i + 3] && t[i + 3] == t[i + 6]) return t[i];
    }
    /* checking diagonals */
    if (t[0] != EMPTY_TILE && t[0] == t[4] && t[4] == t[8]) return t[0];
    if (t[2] != EMPTY_TILE && t[2] == t[4] && t[4] == t[6]) return t[2];
    return -1;

}

/* plays a turn for a given player using the current board state */
/* this function will prompt the user to enter a coordinate */
/* if a given coordinate is invalid, it will ask again */
/* upon completion of the turn, the function will return the updated board state */
struct BoardState playTurn(int playerNum, struct BoardState state) {
    int pos = -1;
    printf("\n\n\n***\nPlayer %c, your turn!\n***\n\n", playerNum == X_TILE ? 'X' : 'O');

    /* loop until a valid coordinate is given */
    while (1) {
        displayBoard(state);
        printf("\nEnter the coordinate you wish to place an %c:", playerNum == X_TILE ? 'X' : 'O');
        if (scanf("%d", &pos) && pos >= 1 && pos <= 9) { /* checking for valid number */
            pos -= 1; /* change coordinate to 0 indexed for array */
            if (state.tiles[pos] != EMPTY_TILE) {
                printf("\n\nYou can't place an %c here. Please select a different coordinate.\n\n", playerNum == X_TILE ? 'X' : 'O');
            } else { /* change the state and return it */
                state.tiles[pos] = playerNum;
                return state;
            } 
        } else {
            /* skip over invalid input, and restart the loop to ask for a coordinate again */
            printf("\nIncorrect coordinate! Please enter a number 1-9\n");
            while (getchar() != '\n');
        }
    }
}