#include "Bullet.hpp"

#include <QTimer>

//Define the bullet's speed
const int Bullet::Speed = -20;

Bullet::Bullet() : Projectile(Bullet::Speed) {

    //Set the size
    setRect(0,0,10,50);
}

