#include "Shooter.hpp"
#include "Projectile.hpp"
#include "SmartScene.hpp"
#include "Game.hpp"

//Consturctor
Shooter::Shooter() {}

//Fire a projectile
void Shooter::fire(Projectile *p) {

    //Set up the projectile
    p->setup();

    //Add the projectile to the scene
    theGame->theScene->addItem(p);
}
