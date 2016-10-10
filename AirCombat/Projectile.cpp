#include "Projectile.hpp"
#include "SmartScene.hpp"
#include "Shooter.hpp"
#include "Game.hpp"

#include <QGraphicsScene>

//Constructor
//If r is true, returns a positive speed instead of a negative one
Projectile::Projectile(const Shooter* o, uint s, uint d, bool r)
    : AutoMove(r?s:-(int)s), Owner(o), reverse(r), damage(d) {}

//Get the damage of the projectile
uint Projectile::getDamage() const { return damage; }

//Returns true if the projectile hurts enemies
//Returns false if hte projectile hurts the player
bool Projectile::hurtsEnemy() const { return !reverse; }

#include<QDebug>
//The projectile's afterTurn function
bool Projectile::afterMove() {

    //If the Projectile is off the screen, then delete it
    if (pos().y() < -(int)getHeight() || pos().y() >= Game::Height ) {

        qDebug() << "Time to die";
        //Remove this item
        theGame->theScene->removeItem(this);
        qDebug() << "Done with afterMove";

        return false;
    }

    return true;
}

//The projectile's beforeTurn function
bool Projectile::beforeTurn() { return true; }

//Setup projectile
void Projectile::setup()
{

    //If the projecitle is normal, set the starting position
    if (!reverse) setPos(Owner->getX()+Owner->getWidth()/2-getWidth()/2,Owner->getY());

    //If the projectile is travelling in reverse
    else {

        //Rotate the image
        setTransformOriginPoint(getWidth()/2,getHeight()/2);
        setRotation(180);

        //Set the starting position
        setPos(Owner->getX()+Owner->getWidth()/2-getWidth()/2,Owner->getY()+getHeight());
    }
}
