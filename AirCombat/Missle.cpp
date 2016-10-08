#include "Missle.hpp"
#include "Shooter.hpp"

#include <QTimer>
#include <SoundManager.hpp>

//Define the Missle's stats
const uint Missle::Speed = 12;
const uint Missle::Damage = 8;

//Define the Missle's size
const int Missle::pixelWidth = 20;
const int Missle::pixelHeight = 62;

//Constructor
Missle::Missle(Shooter *o) : Projectile(o, Speed, Damage) {

    //Draw the Missle
    setPixmap(QPixmap(":/images/images/Missle.png"));

    //Play the Missle sound
    SoundManager::newSound("qrc:/sounds/sounds/Missle.mp3");
}

//Return the size of the Missle
int Missle::getWidth() const { return pixelWidth; }
int Missle::getHeight() const { return pixelHeight; }
