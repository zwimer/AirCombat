#include "Projectile.hpp"

//Constructor
Projectile::Projectile(uint s) : AutoMove(-(int)s) {}

//The projectile's afterMove function
void Projectile::afterMove() {}

//The projectile's beforeMove function
bool Projectile::beforeMove() { return true; }
