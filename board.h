struct BoardState {
    int tiles[9];
};

enum Tile {
    EMPTY_TILE = 0,
    X_TILE= 1,
    O_TILE = 2
};


void displayBoard(struct BoardState);
int checkWin(struct BoardState);
struct BoardState playTurn(int, struct BoardState);
