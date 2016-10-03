#ifndef GAME_H
#define GAME_H

#include "Score.hpp"
#include "Player.hpp"

#include <QObject>

class Game : public QObject {
    Q_OBJECT;
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

public slots:

    //Spawn enemies
    void spawn();

};

//Global variable
extern Game *theGame;

#endif // GAME_H
