#include "Shooter.hpp"
#include "Game.hpp"

//Consturctor
Shooter::Shooter(Shooter* p) {

    //Set the owner to p
    Owner = p;
}

//Destructor
Shooter::~Shooter() {}

//Fire
void Shooter::fire(Projectile *p) {

    //Set the location of the projectile
    p->setPos(Owner->x(),Owner->y());

    //Add the bullet to the scene
    theGame->theScene->addItem(p);

}
