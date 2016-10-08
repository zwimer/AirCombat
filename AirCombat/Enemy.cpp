#include "Enemy.hpp"
#include "Player.hpp"
#include "Score.hpp"
#include "Game.hpp"
#include "SmartScene.hpp"
#include "BasicEnemy.hpp"    //DELETE
#include "FastEnemy.hpp"    //DELETE

#include <vector>
#include <stdlib.h>

//Constructor
Enemy::Enemy(uint s, uint h) : AutoMove(s), health(h) {}

//Override the enemy's spawn location if need be
void Enemy::spawn() {}

#include<QDebug>
//Decrease health and return true if this enemy is dead
bool Enemy::decreaseHealth(uint d)
{ health -= d; return health <= 0; }

//Default do nothing
void Enemy::healthChanged(uint) {}

//Check if the enemy was hit
//If so, remove whatever you need
bool Enemy::checkHit() {

    //Becomes true if health < 0
    bool isDead = false;

    //A projectile pointer
    Projectile *p;

    //A vector of items to delete
    std::vector<QGraphicsItem*> toDelete;

    //If projectile collides with enemy, destroy both
    QList<QGraphicsItem*> items = collidingItems();
    for(int i = 0; i < items.size(); i++)

        //If the projectile hits an enemy
        if ((p = dynamic_cast<Projectile*>(items[i])) != NULL) {

            //Reduce the enemy's health
            isDead = decreaseHealth(p->getDamage());

            //Note that this projectile should be deleted
            toDelete.push_back(items[i]);
        }

    //Delete all the colliding projectiles
    for(int i = 0; i < (int)toDelete.size(); i++) {
        theGame->theScene->removeItem(toDelete[i]);
        delete toDelete[i];
    }

    //Update the enemy sub-class
    if (toDelete.size()) this->healthChanged(health);

    //If the enemy is still alive, return true
    if (!isDead) return true;

    //Increase the score
    theGame->theScore->increase(getScoreValue());

    //Delete this enemy
    scene()->removeItem(this);
    delete this;

    //The enemy is dead
    return false;
}

//Called by game to spawn an enemy
Enemy* Enemy::spawnEnemy() {

    //Create a new enemy
    Enemy *e;

    //Randomize which, prefer basic
    if (rand()%7<5) e = new BasicEnemy();    //CHANGE
    else e = new FastEnemy();

    //Randomize location
    e->setPos(rand()%(Game::Width - e->getWidth()), -(int)e->getHeight());

    //Possibly override random location
    e->spawn();

    //Return the new enemy
    return e;
}

//Call before every move
bool Enemy::beforeTurn() {

    //If the enemy collides with the player, game over
    QList<QGraphicsItem *> items = collidingItems();
    for(int i = 0; i < items.size(); i++)
        if (dynamic_cast<const Player *>(items[i]) != NULL)
            theGame->GameOver();

    //Check if the plane was hit
    return checkHit();
}

//Call after every move
void Enemy::afterTurn() {

    //If the Enemy is off the screen, then delete it
    if (pos().y() > scene()->height()) {

        //Decrement health
        theGame->P1->health->decrease(1);

        //Remove this item
        scene()->removeItem(this);
        delete this;
    }

    //Check if the plane was hit
    checkHit();
}
