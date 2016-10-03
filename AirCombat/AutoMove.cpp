#include "AutoMove.hpp"

AutoMove::AutoMove(uint s) : speed(s) {}

uint AutoMove::getSpeed() const {
    return speed;
}
