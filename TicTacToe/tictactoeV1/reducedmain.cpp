#include <iostream>
using std::cout;
using std::cin;
using std::endl;

char*  getSquare(int box, char** board, int BOARD_SIZE) {
    int currentBoxIndex = 0;
    for(int i = 0;i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (++currentBoxIndex == box) {
                return  &board[i][j] ;
            }
        }
    }
    return *board;
}

int checkPlayerBoard(char player, int BOARD_SIZE, char** board) {
    int largestItems[] = {0, 0, 0, 0}; // stores the largest
    for(int i = 0; i < BOARD_SIZE; i++){
        int seenInRow = 0;
        int seenInCols = 0;
        for(int j = 0; j < BOARD_SIZE; j++){
            if(i==j){
                if(board[i][j] == player){
                    largestItems[0]++;
                }
            }

            if((j+i) == BOARD_SIZE - 1) {
                if(board[i][j] == player){
                    largestItems[1]++;
                }
            }

            if(board[i][j] == player){
                seenInRow++;
            }

            if(board[j][i] == player){
                seenInCols++;
            }
        }

        if(seenInRow >= largestItems[2]){
            largestItems[2] = seenInRow;
        }

        if(seenInCols >= largestItems[3]){
            largestItems[3] = seenInCols;
        }
    }

    for(int i : largestItems){
        if(largestItems[0] < largestItems[i]){
            largestItems[0] = largestItems[i];
        }
    }

    return largestItems[0];

}

bool hasWon(char  mark, int BOARD_SIZE, char** board) {
    return checkPlayerBoard(mark, BOARD_SIZE, board) == BOARD_SIZE;
}

int main() {

    const int BOARD_SIZE = 3;
    const int MAX = BOARD_SIZE * BOARD_SIZE;
    char** board = new char *[BOARD_SIZE];
    for(int row = 0; row < BOARD_SIZE; row++){
        board[row] = new char[BOARD_SIZE];
    }
    // initialize
    for(int row = 0; row < BOARD_SIZE; row++){
        for(int col = 0; col < BOARD_SIZE; col++){
            board[row][col] = ' ';
        }
    }
    // create our players
    char players[2] = {'X', 'O'};
    // keep track of turns
    int occupiedSquares = 0;
    bool endGame = false;
    while(!endGame){
        for(char playerMark : players) {
            int boxNumber;

            if(occupiedSquares == MAX){
                endGame = true;
                cout << "DRAW!";
                break;
            }
            cout << "Player " << playerMark << ": which square number (1-9)? ";
            std::cin >> boxNumber;

            while(boxNumber < 1 || boxNumber > MAX){
                cout << "Invalid square, please try again: ";
                std::cin >> boxNumber;
            }

            while(*getSquare(boxNumber, board, BOARD_SIZE) != ' ') {
                cout << "Square already chosen, please try again: " ;
                cin >> boxNumber;
            }

            *getSquare(boxNumber, board, BOARD_SIZE) = playerMark;
            occupiedSquares++;
            if(hasWon(playerMark, BOARD_SIZE, board)){
                cout << "PLAYER " << playerMark << " WINS!";
                endGame = true;
                break;
            }
            cout << endl;
        }
    }
    delete [] board;
    return 0;
}
