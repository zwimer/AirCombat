#ifndef GAME_H
#define GAME_H

#include "Score.hpp"
#include "Player.hpp"

class Game {

public:
    Game(QWidget *parent = NULL);

    QGraphicsScene * theScene;
    Player *P1;
    Score *theScore;
private:

};



#endif // GAME_H
