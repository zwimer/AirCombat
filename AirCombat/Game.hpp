#ifndef GAME_H
#define GAME_H

#include "Health.hpp"
#include "Score.hpp"
#include "Player.hpp"

class Game {

public:
    Game(QWidget *parent = NULL);

    QGraphicsScene * theScene;
    Player *P1;
    Score *theScore;
    Health *P1Health;
private:

};

//Global variable
extern Game *theGame;

#endif // GAME_H
