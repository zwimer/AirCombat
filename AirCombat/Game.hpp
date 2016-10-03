#ifndef GAME_H
#define GAME_H

#include "Score.hpp"
#include "Player.hpp"

class Game {

public:

    //Constructor
    Game();

    //Representation
    Player *P1;
    Score *theScore;
    QGraphicsScene *theScene;

    //Static const variables
    static const uint Height;
    static const uint Width;

private:

};

//Global variable
extern Game *theGame;

#endif // GAME_H
