#include "Bullet.hpp"
#include "Shooter.hpp"

#include <QTimer>
#include <SoundManager.hpp>

//Define the bullet's speed
const uint Bullet::Speed = 20;

//Define the bullet's size
const int Bullet::pixelWidth = 6;
const int Bullet::pixelHeight = 40;

//Constructor
Bullet::Bullet() : Projectile(Bullet::Speed) {

    //Draw the bullet
    setPixmap(QPixmap(":/images/images/Bullet.png"));

    //Play the bullet sound
    SoundManager::newSound("qrc:/sounds/sounds/Bullet.mp3");
}

#include <QDebug>
//Set the bullet's position
void Bullet::setPosition(Shooter* Owner) {
    setPos(Owner->getX()+Owner->getWidth()/2-pixelWidth/2,Owner->getY());

    qDebug() << "X = " << Owner->getX() << "+" << Owner->getWidth()/2 << "-" << pixelWidth/2;
    qDebug() << "X: " << Owner->x()+Owner->getWidth()/2;
    qDebug() << Owner->getY();


}
