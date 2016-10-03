#include "BasicEnemy.hpp"
#include "Health.hpp"
#include "Game.hpp"

#include <stdlib.h>
#include <QTimer>
#include <QGraphicsScene>


BasicEnemy::BasicEnemy() {

    //Randomize location
    setPos(rand()%(800-100), 0); //CHANGE

    //Set the size
    setRect(0,0,100,100);

    //Connect the move function to a timer
    QTimer *t = new QTimer();
    connect(t, SIGNAL(timeout()), this, SLOT(move()));

    //Have the timer call move every 50 ms
    t->start(50);
}

//The bullet's move function
void BasicEnemy::move() {

    //Move
    setPos(x(),y()+10);

    //If the BasicEnemy is off the screen, then delete it
    if (pos().y() > scene()->height()) {

        //Decrement health
        theGame->P1->health->decrease(1);

        scene()->removeItem(this);
        delete this;
    }
}
