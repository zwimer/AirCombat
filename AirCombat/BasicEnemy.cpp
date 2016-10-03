#include "BasicEnemy.hpp"
#include "Health.hpp"
#include "Game.hpp"

#include <stdlib.h>
#include <QTimer>
#include <QGraphicsScene>

const int BasicEnemy::Speed = 10;

BasicEnemy::BasicEnemy() : Enemy(BasicEnemy::Speed) {

    //Randomize location
    setPos(rand()%(800-100), 0); //CHANGE

    //Set the size
    setRect(0,0,100,100);

    //Connect the move function to a timer
    QTimer *t = new QTimer();
    connect(t, SIGNAL(timeout()), this, SLOT(move()));

    //Have the timer call move every 50 ms
    t->start(50);
}
