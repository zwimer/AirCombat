#ifndef BULLET_H
#define BULLET_H

#include "Projectile.hpp"

//Forward declerations
class Shooter;

//Note: must first inheret from QObject, THEN from ...
class Bullet : public Projectile {
public:

    //Constructor
    Bullet();

    //Get the bullet's height
    int getHeight() const;

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
