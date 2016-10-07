#include "AutoMove.hpp"

#include <QTimer>

AutoMove::AutoMove(int s) : speed(s) {

    //Connect the move function to a timer
    QTimer *t = new QTimer();
    connect(t, SIGNAL(timeout()), this, SLOT(move()));

    //Have the timer call move every 25 ms
    t->start(25);
}

int AutoMove::getSpeed() const {
    return speed;
}


//The bullet's move function
void AutoMove::move() {

    //Before move
    if (!beforeMove()) return;

    //Move
    setPos(x(),y()+speed);

    //After move
    afterMove();
}
