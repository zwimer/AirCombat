#ifndef BULLET_H
#define BULLET_H

#include "Projectile.hpp"
#include <QObject>
#include <QGraphicsRectItem>

//Note: must first inheret from QObject, THEN from ...
class Bullet : public Projectile {
public:
    Bullet();

private:

    //The bullet's speed
    static const int Speed;
};



#endif
