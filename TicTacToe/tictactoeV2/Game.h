
#ifndef A2_GAME_H
#define A2_GAME_H


#include "Player.h"

class Game {
public:

    Game(Player* p1, Player* p2);
    ~Game();
    Player* getSquare(int);
    void occupy(Player&, int);
    void checkBoard();
    Player* getWinner();

    void display();
    static const int BOARD_SIZE = 3;

private:

    Player* p1;
    Player* p2;
    Player **board;
    Player* winner;

    bool hasWon(Player &player);
    int checkPlayerFirstDiagonal(Player&);
    int checkPlayerSecondDiagonal(Player&);
    int checkPlayerRows(Player&);
    int checkPlayerColumns(Player&);

};


#endif //A2_GAME_H
