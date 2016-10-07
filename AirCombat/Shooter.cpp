#include "Shooter.hpp"
#include "Projectile.hpp"
#include "Game.hpp"

//Consturctor
Shooter::Shooter() {}

//Fire a projectile
void Shooter::fire(Projectile *p, Shooter *Turret) {

    //Set the location of the projectile
    if (!Turret) p->setPosition(this);
    else p->setPosition(Turret);

    //Add the bullet to the scene
    theGame->theScene->addItem(p);
}

int Shooter::getX() const { return x(); }
int Shooter::getY() const { return y(); }
