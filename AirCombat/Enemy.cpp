#include "Enemy.hpp"
#include "Game.hpp"

#include <QTimer>
#include <QGraphicsScene>

//Constructor
Enemy::Enemy(uint s) : AutoMove(s) {

    //Connect the move function to a timer
    QTimer *t = new QTimer();
    connect(t, SIGNAL(timeout()), this, SLOT(move()));

    //Have the timer call move every 50 ms
    t->start(50);
}

//Call before every move
bool Enemy::beforeMove() { return true; }

//Call after every move
void Enemy::afterMove() {

    //If the BasicEnemy is off the screen, then delete it
    if (pos().y() > scene()->height()) {

        //Decrement health
        theGame->P1->health->decrease(1);

        //Remove this item
        scene()->removeItem(this);
        delete this;
    }
}
