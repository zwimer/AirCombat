#include "Enemy.hpp"
#include "Player.hpp"
#include "Game.hpp"

#include <stdlib.h>

#include <QTimer>
#include <QGraphicsScene>

//Constructor
Enemy::Enemy(uint s) : AutoMove(s) {

    //Connect the move function to a timer
    QTimer *t = new QTimer();
    connect(t, SIGNAL(timeout()), this, SLOT(move()));

    //Have the timer call move every 50 ms
    t->start(20);
}

//Sets the enemy's position
void Enemy::spawn() {

    //Randomize location
    setPos(rand()%(Game::Width - getWidth()), -(int)getHeight());
}

//Call before every move
bool Enemy::beforeMove() {

    //If the enemy collides with the player, game over
    QList<QGraphicsItem *> items = collidingItems();
    for(int i = 0; i < items.size(); i++)
        if (dynamic_cast<const Player *>(items[i]) != NULL)
            theGame->GameOver();

    //To satisfy the compiler
    return true;
}

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
