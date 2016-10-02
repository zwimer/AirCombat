#include "Bullet.hpp"
#include "Enemy.hpp"
#include "Game.hpp"



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

    //If bullet collides with enemy, destroy both
    QList<QGraphicsItem *> items = collidingItems();
    for(int i = 0; i < items.size(); i++)
        if (typeid(*items[i]) == typeid(Enemy)) {

            //Increase the score
            theGame->theScore->increase(1); //CHANGE

            //remove them both
            scene()->removeItem(items[i]);
            scene()->removeItem(this);

            //Prevent memory leaks
            delete items[i];
            delete this;

            //Don't move becasue there was a collision
            return;
        }

    //CHANGE - also check afterwards
    //CHANGE - could be > 1 collision

    //Move
    setPos(x(),y()-20);

    //If the bullet is off the screen, then delete it
    if (pos().y() + this->rect().height() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
