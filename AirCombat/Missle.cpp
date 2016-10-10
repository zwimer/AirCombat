#include "Missle.hpp"

//Define the Missle's stats
const uint Missle::Speed = 160;
const uint Missle::Damage = 80;

//Define the Missle's size
const int Missle::pixelWidth = 20;
const int Missle::pixelHeight = 62;

//Constructor
Missle::Missle(const Shooter *o, bool r) : Projectile(o, Speed, Damage,r ) {

    //Draw the Missle
    setPixmap(QPixmap(":/images/images/Missle.png"));

    //Play the Missle sound
    playSound("qrc:/sounds/sounds/Missle.mp3");
}

//Return the size of the Missle
int Missle::getWidth() const { return pixelWidth; }
int Missle::getHeight() const { return pixelHeight; }
