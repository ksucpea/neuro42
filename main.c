#include <stdio.h>
#include "board.h"

void run() {
    struct BoardState state = {EMPTY_TILE};
    int winner = -1, numTurns = 0, playerTurn = X_TILE;
    char firstPlayer;

    /* anything other than an X char will let player O go first */
    printf("Welcome to Tic Tac Toe\nChoose which player to go first (X or O):");
    firstPlayer = getchar();
    playerTurn = firstPlayer == 'X' || firstPlayer == 'x' ? X_TILE : O_TILE;

    /* loop while no one has won and the board still has tiles remaining */
    while (winner == -1 && numTurns < 9) {
        state = playTurn(playerTurn, state);
        winner = checkWin(state);
        playerTurn = playerTurn == X_TILE ? O_TILE : X_TILE; /* switch players */
        numTurns++;
    }

    /* end of game, check if draw or winner and display final board */
    printf("\n\n\n");
    if (numTurns >= 9 && winner == -1) {
        printf("***\nDraw! Nobody wins.\n***\n\n");
    } else {
        printf("***\nPlayer %c wins!\n***\n\n", winner == X_TILE ? 'X' : 'O');
    }
    displayBoard(state);

    /* wait for enter to replay */
    printf("\n\n\nPress ENTER to play again.");
    getchar();
    while (getchar() != '\n') {
    }
    run();
}

int main() {
    run();
    return 0;
}