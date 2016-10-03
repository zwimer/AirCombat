#ifndef GAME_H
#define GAME_H

#include "Score.hpp"
#include "Player.hpp"

class Game {

public:
    Game();

    QGraphicsScene *theScene;
    Player *P1;
    Score *theScore;
private:

};

//Global variable
extern Game *theGame;

#endif // GAME_H
