#include "Missle.hpp"
#include "Shooter.hpp"

#include <QTimer>
#include <SoundManager.hpp>

//Define the Missle's speed
const uint Missle::Speed = 15;

//Define the Missle's size
const int Missle::pixelWidth = 20;
const int Missle::pixelHeight = 62;

//Constructor
Missle::Missle() : Projectile(Missle::Speed) {

    //Draw the Missle
    setPixmap(QPixmap(":/images/images/Missle.png"));

    //Play the Missle sound
    SoundManager::newSound("qrc:/sounds/sounds/Missle.mp3");
}

//Return the height of the Missle
int Missle::getHeight() const { return pixelHeight; }

//Set the Missle's position
void Missle::setPosition(Shooter* Owner) {
    setPos(Owner->getX()+Owner->getWidth()/2-pixelWidth/2,Owner->getY());
}
