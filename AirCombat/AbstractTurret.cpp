#include "AbstractTurret.hpp"
#include "Missle.hpp"

//Constructor
AbstractTurret::AbstractTurret(Shooter* o, int x, int y, uint t)
    : Owner(o), offsetX(x), offsetY(y) {

    //Create an AbstractTurret
    timer = new QTimer();

    //Connect the turret to the shoot function
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(shoot()));

    //Start the turret if t != 0
    //Otherwise, note that t = 0
    if (t) timer->start(t);
    else timer->setInterval(0);
}

//Set fire rate
void AbstractTurret::setFireRate(uint t) {

    //If t == 0, stop and note that t = 0
    if (!t) {
        timer->stop();
        timer->setInterval(0);
    }

    //If the turret is already running, change the interval
    else if (timer->interval()) timer->setInterval(t);

    //Otherwise, start the turret
    else timer->start(t);
}

//Return the turret's location
int AbstractTurret::getX() const { return Owner->getX()+offsetX; }
int AbstractTurret::getY() const { return Owner->getY()+offsetY; }

//Turrets have no size... at least not yet
uint AbstractTurret::getWidth() const { return 0; }
uint AbstractTurret::getHeight() const { return 0; }

//Fire the turret
void AbstractTurret::shoot() { fire(createProjectile()); }
