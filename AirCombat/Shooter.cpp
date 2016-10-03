#include "Shooter.hpp"
#include "Game.hpp"

//Consturctor
Shooter::Shooter() {}

//Destructor
Shooter::~Shooter() {}

//Fire
void Shooter::fire(Projectile *p) {

    //Set the location of the projectile
    p->setPos(x(),y());

    //Add the bullet to the scene
    theGame->theScene->addItem(p);
}
