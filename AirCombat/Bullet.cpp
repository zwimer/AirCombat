#include "Bullet.hpp"

//Define the Bullet's stats
const uint Bullet::Speed = 80;
const uint Bullet::Damage = 20;

//Define the Bullet's size
const int Bullet::pixelWidth = 6;
const int Bullet::pixelHeight = 40;

//Constructor
Bullet::Bullet(const Shooter *o, bool r) : Projectile(o, Speed, Damage, r) {

    //Draw the Bullet
    setPixmap(QPixmap(":/images/images/Bullet.png"));

    //Play the Bullet sound
    playSound("qrc:/sounds/sounds/Bullet.mp3");
}

//Return the size of the Bullet
int Bullet::getWidth() const { return pixelWidth; }
int Bullet::getHeight() const { return pixelHeight; }
