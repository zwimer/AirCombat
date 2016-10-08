#include "Turret.hpp"
#include "Missle.hpp"

//Constructor
Turret::Turret(Shooter* o, int x, int y, uint t)
    : Owner(o), offsetX(x), offsetY(y) {

    //Create a timer
    timer = new QTimer();

    //Connect the timer to the shoot function
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(shoot()));

    //Start the timer if t != 0
    //Otherwise, note that t = 0
    if (t) timer->start(t);
    else timer->setInterval(0);
}

//Set fire rate
void Turret::setFireRate(uint t) {

    //If t == 0, stop and note that t = 0
    if (!t) {
        timer->stop();
        timer->setInterval(0);
    }

    //If the timer is already running, change the interval
    else if (timer->interval()) timer->setInterval(t);

    //Otherwise, start the timer
    else timer->start(t);
}

//Return the turret's location
int Turret::getX() const { return Owner->x()+offsetX; }
int Turret::getY() const { return Owner->y()+offsetY; }

//Turrets have no size... at least not yet
uint Turret::getWidth() const { return 0; }
uint Turret::getHeight() const { return 0; }

//Fire the turret
void Turret::shoot() { fire(new Missle(this)); }
