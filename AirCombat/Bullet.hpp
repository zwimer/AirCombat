#ifndef BULLET_H
#define BULLET_H

#include "Shooter.hpp"
#include "Projectile.hpp"

//Note: must first inheret from QObject, THEN from ...
class Bullet : public Projectile {
public:

    //Constructor
    Bullet();

    //Set Bullet's starting position
    void setPosition(Shooter *Owner);

private:

    //The bullet's speed
    static const uint Speed;

    //The bullet's size
    static const int pixelWidth;
    static const int pixelHeight;
};



#endif
