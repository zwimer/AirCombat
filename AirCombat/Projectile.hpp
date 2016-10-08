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
    Projectile(uint s, uint d);

    //Returns the damage done if an enemy is hit
    uint getDamage() const;

    //Set's the position
    void setPosition(Shooter* Owner);

protected:

    //Get the projectile's size;
    virtual int getWidth() const = 0;
    virtual int getHeight() const = 0;

    //AutoMove functions
    void afterMove();
    bool beforeMove();

    //Representation
    uint damage;
};

#endif // PROJECTILE_H
