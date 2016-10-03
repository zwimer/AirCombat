#include "Moveable.hpp"

Moveable::Moveable(uint s) : speed(s) {}

uint Moveable::getSpeed() const {
    return speed;
}
