#include "Missile.hpp"

//Define the Missile's stats
const uint Missile::Speed = 160;
const uint Missile::Damage = 80;

//Define the Missile's size
const int Missile::pixelWidth = 20;
const int Missile::pixelHeight = 62;

//Constructor
Missile::Missile(const Shooter *o, bool r) : Projectile(o, Speed, Damage,r ) {

    //Draw the Missile
    setPixmap(QPixmap(":/images/images/Missile.png"));

    //Play the Missile sound
    playSound("qrc:/sounds/sounds/Missile.mp3");
}

//Return the size of the Missile
int Missile::getWidth() const { return pixelWidth; }
int Missile::getHeight() const { return pixelHeight; }
