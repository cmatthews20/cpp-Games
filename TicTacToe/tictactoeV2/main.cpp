#include <iostream>
#include "Player.h"
#include "Game.h"

using std::cout;
using std::cin;
using std::endl;

int main() {

    Player p1("X");
    Player p2("O");
    Player* players [2] = {&p1, &p2};
    Game g(&p1, &p2);

    int turn = 0;
    while(turn <= Game::BOARD_SIZE * Game::BOARD_SIZE - 1){
        for(int p = 0; p < 2; p++) {
            Player* current = players[p];
            int box;
            cout << "Player " + current->getMark()+ ": which square number (1-9)? ";
            std::cin >> box;
            // check if valid
            while(!g.getSquare(box)->getMark().empty()) {
                cout << "Square already chosen, please try again: " ;
                cin >> box;
            }
            g.occupy(*current , box);
            g.display();
            g.checkBoard();
            if(g.getWinner()){
                cout << "PLAYER " + g.getWinner()->getMark() << " WINS!";
                return 0;
            }
            cout << endl;
            turn++;
        }
    }

    cout << "DRAW!";

    return 0;
}
