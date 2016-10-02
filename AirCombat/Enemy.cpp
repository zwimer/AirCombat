#include "Enemy.hpp"
#include <stdlib.h>
#include <QTimer>
#include <QGraphicsScene>


Enemy::Enemy() {

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

//The bullet's move function
void Enemy::move() {

    //Move
    setPos(x(),y()+10);

    //If the Enemy is off the screen, then delete it
    if (pos().y() > scene()->height()) {
        scene()->removeItem(this);
        delete this;
    }
}
