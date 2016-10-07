#include "Enemy.hpp"
#include "Player.hpp"
#include "Game.hpp"

#include <stdlib.h>

#include <QTimer>
#include <QGraphicsScene>

#include "BasicEnemy.hpp"    //DELETE

//Constructor
Enemy::Enemy(uint s) : AutoMove(s) {}

//Override the enemy's spawn location if need be
void Enemy::spawn() {}

//Called by game to spawn an enemy
Enemy* Enemy::spawnEnemy() {

    //Create a new enemy
    Enemy *e = new BasicEnemy();    //CHANGE

    //Randomize location
    e->setPos(rand()%(Game::Width - e->getWidth()), -(int)e->getHeight());

    //Possibly override random location
    e->spawn();

    //Return the new enemy
    return e;
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
