#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "AutoMove.hpp"

class Projectile: public AutoMove {
public:

    //Constructor
    //Takes unsigned speed argument
    Projectile()=delete;
    Projectile(uint s);

    //Make class abstract
    virtual ~Projectile()=0;

protected:
    void afterMove();
    bool beforeMove();

};

#endif // PROJECTILE_H
