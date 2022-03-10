
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//Obtains real square position in array from number (1-9)
char* getSquare(int box, char** board, int BOARD_SIZE) {
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

//Checks the occurrences of a particular player in the downwards diagonal, left to right
int checkPlayerFirstDiagonal(char player, int BOARD_SIZE, char** board) {
    int occupancies=0;

    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            if(i==j){
                if(board[i][j] == player){
                    occupancies++;
                }
            }
        }
    }
    return occupancies;
}

//Checks the occurrences of a particular player in the upwards diagonal, left to right
int checkPlayerSecondDiagonal(char player, int BOARD_SIZE, char** board) {
    int occupancies=0;
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            if((j+i) == BOARD_SIZE - 1) {
                if(board[i][j] == player){
                    occupancies++;
                }
            }
        }
    }
    return occupancies;
}

//Checks the occurrences of a particular player in their most frequent row
int checkPlayerRows(char player, int BOARD_SIZE, char** board) {
    int largest=0;
    for(int i = 0; i < BOARD_SIZE; i++){
        int seenInRow = 0;
        for(int j = 0; j < BOARD_SIZE; j++){
            if(board[i][j] == player){
                seenInRow++;
            }
        }
        if(seenInRow>=largest){
            largest = seenInRow;
        }
    }
    return largest;
}

//Checks the occurrences of a particular player in their most frequent column
int checkPlayerColumns(char player, int BOARD_SIZE, char** board) {
    int largest=0;
    for(int i = 0; i < BOARD_SIZE; i++){
        int seenInCols=0;
        for(int j = 0; j < BOARD_SIZE; j++){
            if(board[j][i] == player){
                seenInCols++;
            }
        }
        if(seenInCols>=largest){
            largest = seenInCols;
        }
    }
    return largest;
}

//Returns true if given player has won
bool hasWon(char  mark, int BOARD_SIZE, char** board) {
    return checkPlayerColumns(mark, BOARD_SIZE, board) == BOARD_SIZE ||
           checkPlayerFirstDiagonal(mark, BOARD_SIZE, board) == BOARD_SIZE ||
           checkPlayerSecondDiagonal(mark, BOARD_SIZE, board) == BOARD_SIZE ||
           checkPlayerRows(mark, BOARD_SIZE, board) == BOARD_SIZE;
}

/*Prints exit message and exits program if argument is a negative number
 *This function shows up several times after a box is inputted to ensure game stops if the player's choice was negative*/
void negNumber(int number){
    if (number < 0){
        cout << "GAME ENDED BY USER! ";
        exit(0);
    }
}

int main() {

    //Initialize and declare some variables
    int box;
    const int BOARD_SIZE = 3;
    const int MAX = BOARD_SIZE * BOARD_SIZE;

    //Create 2D dynamic array for the game board
    char** board = new char *[BOARD_SIZE];
    for(int row = 0; row < BOARD_SIZE; row++){
        board[row] = new char[BOARD_SIZE];
    }

    //Insert empty spaces into entire board to begin
    for(int row = 0; row < BOARD_SIZE; row++){
        for(int col = 0; col < BOARD_SIZE; col++){
            board[row][col] = ' ';
        }
    }

    //Create players
    char players[2] = {'X', 'O'};

    //Keep track of turns
    int occupiedSquares = 0;

    //Initialize end case and loop for tic-tac-toe gameplay
    bool endGame = false;
    while(!endGame){

        //For loop so players can take turns back and forth
        for(int i = 0; i < 2; i++) {
            char playerMark = players[i];

            //Prints draw message when all boxes are filled
            if(occupiedSquares == MAX){
                endGame = true;
                cout << "DRAW!" << endl;
                break;
            }

            //Beginning of turn; asks player what box they want to place their 'piece'
            cout << "Player " << playerMark << ": which square number (1-9)? ";
            std::cin >> box;
            negNumber(box);

            //Prompts player to enter another box until they select a valid number corresponding to a box
            while(box == 0 || box > MAX){
                cout << "Invalid square selected, please try again. ";
                std::cin >> box;
                negNumber(box);
            }

            //Prompts player to enter another box until they select an empty box
            while(*getSquare(box, board, BOARD_SIZE) != ' ') {
                cout << "Square already chosen, please try again. ";
                cin >> box;
                negNumber(box);
            }

            //Put the player's mark in the selected box
            *getSquare(box, board, BOARD_SIZE) = playerMark;
            occupiedSquares++;

            //Prints win message and ends game if someone has won
            if(hasWon(playerMark, BOARD_SIZE, board)){
                cout << "PLAYER " << playerMark << " WINS! ";
                endGame = true;
                break;
            }
        }
    }

    delete [] board;
    return 0;
}