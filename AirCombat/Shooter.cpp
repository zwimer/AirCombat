#include "Shooter.hpp"
#include "Game.hpp"

//Consturctor
Shooter::Shooter(Shooter* o) {
    Owner = o;
}

//Fire a projectile
void Shooter::fire(Projectile *p) {

    //Set the location of the projectile
    p->setPosition(Owner);

    //Add the bullet to the scene
    theGame->theScene->addItem(p);
}
