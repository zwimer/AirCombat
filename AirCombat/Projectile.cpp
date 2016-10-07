#include "Projectile.hpp"
#include "Game.hpp"

#include <QGraphicsScene>

//Constructor
Projectile::Projectile(uint s) : AutoMove(-(int)s) {}

//The projectile's afterMove function
void Projectile::afterMove() {

    //If the Projectile is off the screen, then delete it
    if (pos().y() < -(int)getHeight()) {

        //Remove this item
        theGame->theScene->removeItem(this);
        delete this;
    }

}

//The projectile's beforeMove function
bool Projectile::beforeMove() { return true; }
