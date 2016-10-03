#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "AutoMove.hpp"

class Projectile: public AutoMove
{
public:
    Projectile()=delete;
    Projectile(int s);

protected:
    void afterMove();
    void beforeMove();

};

#endif // PROJECTILE_H
