#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "AutoMove.hpp"

//Forward declarations
class Shooter;

//A class for projectiles
class Projectile: public AutoMove {
public:

    //Delete default constructor
    Projectile()=delete;

    //Takes unsigned speed and damage arguments
    Projectile(Shooter* o, uint s, uint d);

    //Set up the projectile
    void setup();

    //Returns the damage done if an enemy is hit
    uint getDamage() const;

protected:

    //Get the projectile's size;
    virtual int getWidth() const = 0;
    virtual int getHeight() const = 0;

    //Representation
    const Shooter* Owner;
    const uint damage;

private:

    //AutoMove functions
    void afterMove();
    bool beforeMove();
};

#endif // PROJECTILE_H
