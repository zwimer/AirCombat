#include "Bullet.hpp"
#include "Shooter.hpp"

#include <QTimer>

//Define the bullet's speed
const uint Bullet::Speed = 20;

//Define the bullet's size
const int Bullet::pixelWidth = 6;
const int Bullet::pixelHeight = 40;

//Constructor
Bullet::Bullet() : Projectile(Bullet::Speed) {

    //Draw the bullet
    setPixmap(QPixmap(":/images/Bullet.png"));
}

//Set the bullet's position
void Bullet::setPosition(Shooter* Owner) {
    setPos(Owner->x()+Owner->getWidth()/2-pixelWidth/2,Owner->y());
}
