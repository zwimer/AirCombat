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

    //Shooter argument is what shot the projectile
    //Takes unsigned speed, s, and damage, d, argument
    //Last argument is used if the projectile was shot from an enemy
    Projectile(const Shooter* o, uint s, uint d, bool r = false);

    //Set up the projectile
    void setup();

    //Returns the damage done if an enemy is hit
    uint getDamage() const;

    //Returns true if the projectile hurts enemies
    //Returns false if hte projectile hurts the player
    bool hurtsEnemy() const;

private:

    //Get the projectile's size;
    virtual int getWidth() const = 0;
    virtual int getHeight() const = 0;

    //Representation
    const Shooter* Owner;
    const bool reverse;
    const uint damage;

    //AutoMove functions
    void afterMove();
    bool beforeTurn();
};

#endif // PROJECTILE_H
