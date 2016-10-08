#include "Bullet.hpp"
#include "Shooter.hpp"

#include <QTimer>
#include <SoundManager.hpp>

//Define the Bullet's stats
const uint Bullet::Speed = 5;
const uint Bullet::Damage = 2;

//Define the Bullet's size
const int Bullet::pixelWidth = 6;
const int Bullet::pixelHeight = 40;

//Constructor
Bullet::Bullet(Shooter *o) : Projectile(o, Speed, Damage) {

    //Draw the Bullet
    setPixmap(QPixmap(":/images/images/Bullet.png"));

    //Play the Bullet sound
    SoundManager::newSound("qrc:/sounds/sounds/Bullet.mp3");
}

//Return the size of the Bullet
int Bullet::getWidth() const { return pixelWidth; }
int Bullet::getHeight() const { return pixelHeight; }
