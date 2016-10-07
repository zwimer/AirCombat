#include "Enemy.hpp"
#include "Player.hpp"
#include "Score.hpp"
#include "Game.hpp"
#include "BasicEnemy.hpp"    //DELETE

#include <vector>
#include <stdlib.h>

#include <QGraphicsScene>


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

//Check if the enemy was hit
//If so, remove whatever you need
bool Enemy::checkDeath() {

    //A vector of items to delete
    std::vector<QGraphicsItem*> toDelete;

    //If projectile collides with enemy, destroy both
    QList<QGraphicsItem*> items = collidingItems();
    for(int i = 0; i < items.size(); i++)

        //If the projectile hits an enemy
        if (dynamic_cast<const Projectile*>(items[i]) != NULL) {

            //Increase the score
            theGame->theScore->increase(1); //CHANGE

            //Remove them both
            toDelete.push_back(items[i]);
            scene()->removeItem(this);

            //Prevent memory leaks
            delete items[i];
            delete this;

            //Don't move becasue there was a collision
            return false;
        }

    //If no collision, return true
    if (!toDelete.size()) return true;

    //Delete all the colliding projectiles
    for(int i = 0; i < (int)toDelete.size(); i++)
        scene()->removeItem(toDelete[i]);

    //There was a collision
    return false;
}

//Call before every move
bool Enemy::beforeMove() {

    //If the enemy collides with the player, game over
    QList<QGraphicsItem *> items = collidingItems();
    for(int i = 0; i < items.size(); i++)
        if (dynamic_cast<const Player *>(items[i]) != NULL)
            theGame->GameOver();

    //Check if the plane was hit
    return checkDeath();
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

    //Check if the plane was hit
    checkDeath();
}
