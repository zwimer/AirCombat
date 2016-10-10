#include "Enemy.hpp"
#include "Player.hpp"
#include "Score.hpp"
#include "Game.hpp"
#include "SmartScene.hpp"

#include "GunnerEnemy.hpp"    //DELETE
#include "BasicEnemy.hpp"    //DELETE
#include "FastEnemy.hpp"    //DELETE

#include <vector>
#include <stdlib.h>

//Constructor
Enemy::Enemy(uint s, uint h) : AutoMove(s), health(h) {}

//Override the enemy's spawn location if need be
void Enemy::spawn() {}

//Decrease health and return true if this enemy is dead
bool Enemy::decreaseHealth(uint d)
{ health -= d; return health <= 0; }

//Default do nothing
void Enemy::healthChanged(uint) {}

//Called by game to spawn an enemy
Enemy* Enemy::spawnEnemy() {

    //Create a new enemy
    Enemy *e;

    //Randomize which
    int r = rand()%11;
    if (r<6) e = new BasicEnemy();    //CHANGE
    else if (r<9) e = new FastEnemy();
    else e = new GunnerEnemy();

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
void Enemy::afterMove() {

    //If the Enemy is off the screen, then delete it
    if (pos().y() > scene()->height()) {

        //Decrement health
        theGame->P1->health->decrease(1);

        //Remove this item
        scene()->removeItem(this);

        //This item needs to be deleted
        deleteMe();
    }

    //Check if the plane was hit
    else checkHit();
}

//Check if the enemy was hit
//If so, remove whatever you need
bool Enemy::checkHit() {

    //Becomes true if health < 0
    bool isDead = false;

    //A projectile pointer
    Projectile *p;

    //A vector of items to delete
    std::vector<QGraphicsItem*> toRemove;

    //If projectile collides with enemy, destroy both
    QList<QGraphicsItem*> items = collidingItems();
    for(int i = 0; i < items.size(); i++)

        //If the projectile hits an enemy
        if ((p = dynamic_cast<Projectile*>(items[i])) != NULL) {

            //If the projectile only damages the player, ignore it
            if (!p->hurtsEnemy()) continue;

            //Reduce the enemy's health
            isDead = decreaseHealth(p->getDamage());

            //Note that this projectile should be deleted
            toRemove.push_back(items[i]);
            p->deleteMe();
        }

    //Delete all the colliding projectiles
    for(int i = 0; i < (int)toRemove.size(); i++)
        theGame->theScene->removeItem(toRemove[i]);

    //Update the enemy sub-class
    if (toRemove.size()) this->healthChanged(health);

    //If the enemy is still alive, return true
    if (!isDead) return true;

    //Increase the score
    theGame->theScore->increase(getScoreValue());

    //Delete this enemy
    scene()->removeItem(this);
    deleteMe();

    //Note the enemy's death
    return false;
}
