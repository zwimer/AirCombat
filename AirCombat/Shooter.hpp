#ifndef SHOOTER_H
#define SHOOTER_H

#include "Projectile.hpp"

//#include <QGraphicsRectItem>

class Shooter : public QGraphicsRectItem {
public:

    //Constructor
    Shooter();

    //Make class abstract
    virtual ~Shooter()=0;

    //Fire
    void fire(Projectile *p);

private:

};

#endif // SHOOTER_H
