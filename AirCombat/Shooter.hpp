#ifndef SHOOTER_H
#define SHOOTER_H

#include "Projectile.hpp"

//#include <QGraphicsRectItem>

class Shooter : public QGraphicsRectItem {
public:
    Shooter(Shooter *p);
    virtual ~Shooter();

    //Fire
    void fire(Projectile *p);

private:

    //The object that called this constructor
    Shooter* Owner;

};

#endif // SHOOTER_H
