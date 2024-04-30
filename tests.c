#include <assert.h>
#include "board.c"

void testCheckWin() {
    struct BoardState test_wins[] = {
        /* rows */
        {X_TILE, X_TILE, X_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE},
        {EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, X_TILE, X_TILE, X_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE},
        {EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, X_TILE, X_TILE, X_TILE},
        /* columns */
        {X_TILE, EMPTY_TILE, EMPTY_TILE, X_TILE, EMPTY_TILE, EMPTY_TILE, X_TILE, EMPTY_TILE, EMPTY_TILE},
        {EMPTY_TILE, X_TILE, EMPTY_TILE, EMPTY_TILE, X_TILE, EMPTY_TILE, EMPTY_TILE, X_TILE, EMPTY_TILE},
        {EMPTY_TILE, EMPTY_TILE, X_TILE, EMPTY_TILE, EMPTY_TILE, X_TILE, EMPTY_TILE, EMPTY_TILE, X_TILE},
        /* diagonal */
        {X_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, X_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, X_TILE},
        {EMPTY_TILE, EMPTY_TILE, X_TILE, EMPTY_TILE, X_TILE, EMPTY_TILE, X_TILE, EMPTY_TILE, EMPTY_TILE},
    };
    struct BoardState test_loss[] = {
        {X_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE},
        {X_TILE, X_TILE, EMPTY_TILE, X_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE},
        {X_TILE, X_TILE, EMPTY_TILE, X_TILE, X_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE},
        {X_TILE, X_TILE, EMPTY_TILE, X_TILE, EMPTY_TILE, X_TILE, EMPTY_TILE, EMPTY_TILE, X_TILE},
        {X_TILE, X_TILE, O_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE, EMPTY_TILE},
        {X_TILE, X_TILE, O_TILE, EMPTY_TILE, X_TILE, X_TILE, X_TILE, O_TILE, O_TILE,},
    };
    int i;

    for (i = 0; i < 8; i++) {
        assert(checkWin(test_wins[i]) == X_TILE);
        printf("Passed test %d\n", i);
    }
    /* -1 means no one has won */
    for (i = 0; i < 6; i++) {
        assert(checkWin(test_loss[i]) == -1);
        printf("Passed test %d\n", i);
    }
}

int main() {
    testCheckWin();
    printf("All tests passed\n");
    return 0;
}