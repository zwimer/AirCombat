#include "AutoMove.hpp"

AutoMove::AutoMove(int s) : speed(s) {}

int AutoMove::getSpeed() const {
    return speed;
}


//The bullet's move function
void AutoMove::move() {

    //Before move
    beforeMove();

    //Move
    setPos(x(),y()+speed);

    //After move
    afterMove();
}
