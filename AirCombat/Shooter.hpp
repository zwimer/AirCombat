#ifndef SHOOTER_H
#define SHOOTER_H

#include <QGraphicsPixmapItem>

//Forward declerations
class Projectile;

class Shooter : public QGraphicsPixmapItem {
public:

    //Constructor
    Shooter()=delete;
    Shooter(Shooter* o);

    //Fire
    void fire(Projectile *p);

    //This is for the use of the projectile class
    virtual uint getWidth() const = 0;

private:

    //Who shot
    Shooter* Owner;
};

#endif // SHOOTER_H
