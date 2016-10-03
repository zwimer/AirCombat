#include "Enemy.hpp"
#include "Health.hpp"
#include "Game.hpp"

#include <stdlib.h>
#include <QTimer>
#include <QGraphicsScene>

Enemy::Enemy() {}


//The bullet's move function
void Enemy::move() {

    //Move
    setPos(x(),y()+10);

    //If the BasicEnemy is off the screen, then delete it
    if (pos().y() > scene()->height()) {

        //Decrement health
        theGame->P1Health->decrease(1);

        scene()->removeItem(this);
        delete this;
    }
}
