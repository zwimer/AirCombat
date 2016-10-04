#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "AutoMove.hpp"

//Forward declarations
class Shooter;

//A class for projectiles
class Projectile: public AutoMove {
public:

    //Constructor
    //Takes unsigned speed argument
    Projectile()=delete;
    Projectile(uint s);

    //Set's the position
    virtual void setPosition(Shooter* Owner) = 0;

protected:

    //Functions to be called when the bullet moves
    void afterMove();
    bool beforeMove();
};

#endif // PROJECTILE_H
