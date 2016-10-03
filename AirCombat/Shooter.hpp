#ifndef SHOOTER_H
#define SHOOTER_H

#include "Projectile.hpp"

//#include <QGraphicsRectItem>

class Shooter : public QGraphicsRectItem {
public:
    Shooter();
    virtual ~Shooter();

    //Fire
    void fire(Projectile *p);

private:

};

#endif // SHOOTER_H
