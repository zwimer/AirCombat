#include "Bullet.hpp"

#include <QTimer>

//Define the bullet's speed
const int Bullet::Speed = -20;

Bullet::Bullet() : Projectile(Bullet::Speed) {

    //Set the size
    setRect(0,0,10,50);

    //Connect the move function to a timer
    QTimer *t = new QTimer();
    connect(t, SIGNAL(timeout()), this, SLOT(move()));

    //Have the timer call move every 50 ms
    t->start(50);
}

