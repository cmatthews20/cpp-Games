#include "Game.h"
using std::cout;
using std::endl;

Game::Game(Player *p1, Player *p2 )  {
    this->p1 = p1;
    this->p2 = p2;
    winner = nullptr;
    board = new Player *[BOARD_SIZE];
    for(int row = 0; row < BOARD_SIZE; row++){
        board[row] = new Player[BOARD_SIZE];
    }

}

Game::~Game() {
    //clean up char pointers
}

Player* Game::getSquare(int box) {
    int currentBoxIndex = 0;
    for(int i = 0;i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            if(++currentBoxIndex == box){
                //cout << std::to_string(i) + "" + std::to_string(j)   << endl;
                return &board[i][j];
            }
        }
    }
    return nullptr;
}


void Game::checkBoard() {
    if(hasWon(*p1)){
        winner = p1;
    }
    if(hasWon(*p2)){
        winner = p2;
    }
}

bool Game::hasWon(Player &player) {
    return checkPlayerColumns(player) == BOARD_SIZE ||
    checkPlayerFirstDiagonal(player) == BOARD_SIZE ||
    checkPlayerSecondDiagonal(player) == BOARD_SIZE ||
    checkPlayerRows(player) == BOARD_SIZE;
}



Player *Game::getWinner() {
    return winner;
}

void Game::occupy(Player& player, int box) {
    Player& spot = *getSquare(box);
    spot = player;

}

int Game::checkPlayerFirstDiagonal(Player &player) {
    // check diagonal "\"
    int occupancies=0;

    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            if(i==j){
                Player* p = &board[i][j];
                if(p->getMark()==player.getMark()){
                    occupancies++;
                }

            }


        }
    }

    //cout << "player " + player.getMark() + " fd=" + std::to_string(occupancies) << std::endl;
    return occupancies;


}

int Game::checkPlayerSecondDiagonal(Player &player) {
    // check diagonal "/"
    int occupancies=0;
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = BOARD_SIZE - 1; j >= 0; j--){
            if((j+i) == BOARD_SIZE - 1) {
                Player* p = &board[i][j];
                if(p->getMark()==player.getMark()){
                    occupancies++;
                }
            }
        }
    }
    //cout << "player " + player.getMark() + " sd=" + std::to_string(occupancies)  << std::endl;
    return occupancies;
}

int Game::checkPlayerRows(Player &player) {
    int largest=0;
    // check rows
    for(int i = 0; i < BOARD_SIZE; i++){
        int seenInRow = 0;
        for(int j = 0; j < BOARD_SIZE; j++){
            Player* p = &board[i][j];
            if(p->getMark()==player.getMark()){
                seenInRow++;
            }
        }
        if(seenInRow>=largest){
            largest = seenInRow;
        }
    }
    //cout << "player " + player.getMark() + " rows=" + std::to_string(largest)  << std::endl;
    return largest;

}

int Game::checkPlayerColumns(Player &player) {
    // check columns
    int largest=0;
    for(int i = 0; i < BOARD_SIZE; i++){
        int seenInCols=0;
        for(int j = 0; j < BOARD_SIZE; j++){
            Player* p = &board[j][i];
            if(p->getMark()==player.getMark()){
                seenInCols++;
            }
        }
        if(seenInCols>=largest){
            largest = seenInCols;
        }
    }

    //cout << "player " + player.getMark() + " cols=" + std::to_string(largest)  << std::endl;
    return largest;
}

void Game::display() {
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            Player* p = &board[i][j];
            cout << "|\t" +p->getMark() + "\t|\t";
        }
        cout <<  std::endl;
    }

}


