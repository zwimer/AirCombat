#include "BasicEnemy.hpp"
#include "Projectile.hpp"
#include "Score.hpp"
#include "Game.hpp"

#include <QTimer>
#include <QGraphicsScene>

//Constructor
Projectile::Projectile(uint s) : AutoMove(-(int)s) {

    //Connect the move function to a timer
    QTimer *t = new QTimer();
    connect(t, SIGNAL(timeout()), this, SLOT(move()));

    //Have the timer call move every 50 ms
    t->start(50);
}

//The projectile's afterMove function
void Projectile::afterMove() { beforeMove(); }

//The projectile's beforeMove function
bool Projectile::beforeMove() {

    //If projectile collides with enemy, destroy both
    QList<QGraphicsItem *> items = collidingItems();
    for(int i = 0; i < items.size(); i++)

        //If the projectile hits an enemy
        if (dynamic_cast<const BasicEnemy *>(items[i]) != NULL) {

            //Increase the score
            theGame->theScore->increase(1); //CHANGE

            //remove them both
            scene()->removeItem(items[i]);
            scene()->removeItem(this);

            //Prevent memory leaks
            delete items[i];
            delete this;

            //Don't move becasue there was a collision
            return false;
        }

    //CHANGE - could be > 1 collision
    //CHANGE comments
    return true;
}
