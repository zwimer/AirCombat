#include "BasicEnemy.hpp"
#include "Projectile.hpp"
#include "Game.hpp"

#include <QGraphicsScene>

//Constructor
Projectile::Projectile(int s) : AutoMove(s) {

}

void Projectile::afterMove() {
    beforeMove();
}

//The projectile's move function
void Projectile::beforeMove() {

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
            return;
        }

    //CHANGE - could be > 1 collision
}
