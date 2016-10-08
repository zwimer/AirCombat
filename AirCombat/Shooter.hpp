#ifndef SHOOTER_H
#define SHOOTER_H

#include "main.hpp"
#include <QGraphicsPixmapItem>

//Forward declerations
class Projectile;

//Allows sub-classes to shoot projectiles
class Shooter : public QGraphicsPixmapItem {
public:

    //Constructor
    Shooter();

    //Fire
    void fire(Projectile *p);


    virtual int getX() const;
    virtual int getY() const;

    //Get the size of the owner
    virtual uint getWidth() const = 0;
    virtual uint getHeight() const = 0;

protected:

    //Who shot
    Shooter* Owner;
};

#endif // SHOOTER_H
