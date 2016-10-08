#include "Projectile.hpp"
#include "SmartScene.hpp"
#include "Shooter.hpp"
#include "Game.hpp"

#include <QGraphicsScene>

//Constructor
Projectile::Projectile(uint s, uint d) : AutoMove(-(int)s), damage(d) {}

//Get the damage of the projectile
uint Projectile::getDamage() const { return damage; }

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

//Set the Bullet's position
void Projectile::setPosition(Shooter* Owner) {
    setPos(Owner->getX()+Owner->getWidth()/2-getWidth()/2,Owner->getY());
}
