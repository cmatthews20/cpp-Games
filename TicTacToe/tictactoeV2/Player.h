#include <iostream>

#ifndef A2_PLAYER_H
#define A2_PLAYER_H
using std::string;

class Player {
public:
    Player();
    Player( std::string);
    std::string getMark() const;
private:
    std::string mark;
};


#endif //A2_PLAYER_H
