#ifndef SHOOTER_H
#define SHOOTER_H

#include "main.hpp"

#include <QGraphicsPixmapItem>

//Forward declerations
class Projectile;

//Allows sub-classes to shoot projectiles
class Shooter {
public:

    //Constructor
    Shooter();

    //Fire
    void fire(Projectile *p);

    //Get the location of the shooter
    virtual int getX() const = 0;
    virtual int getY() const = 0;

    //Get the size of the owner
    virtual uint getWidth() const = 0;
    virtual uint getHeight() const = 0;
};

#endif // SHOOTER_H
