#include "Bullet.hpp"
#include <QTimer>
#include <QGraphicsScene>


Bullet::Bullet() {

    //Set the size
    setRect(0,0,10,50);

    //Connect the move function to a timer
    QTimer *t = new QTimer();
    connect(t, SIGNAL(timeout()), this, SLOT(move()));

    //Have the timer call move every 50 ms
    t->start(50);
}

//The bullet's move function
void Bullet::move() {

    //Move
    setPos(x(),y()-10);

    //If the bullet is off the screen, then delete it
    if (pos().y() + this->rect().height() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
