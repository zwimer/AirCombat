#include "Enemy.hpp"
#include "Health.hpp"
#include "Game.hpp"

#include <QGraphicsScene>

//Constructor
Enemy::Enemy(int s) : AutoMove(s) {}

//Call before every move
bool Enemy::beforeMove() { return true; }

//Call after every move
void Enemy::afterMove() {

    //If the BasicEnemy is off the screen, then delete it
    if (pos().y() > scene()->height()) {

        //Decrement health
        theGame->P1Health->decrease(1);

        //Remove this item
        scene()->removeItem(this);
        delete this;
    }
}
