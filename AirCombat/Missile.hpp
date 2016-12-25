#ifndef MISSILE_H
#define MISSILE_H

#include "Projectile.hpp"

//Forward declerations
class Shooter;

//A Missile
class Missile : public Projectile {
public:

    //Constructor
    Missile() = delete;
    Missile(const Shooter *o, bool r = false);

private:

    //Get the Missile's size
    int getHeight() const;
    int getWidth() const;

    //The Missile's stats
    static const uint Speed;
    static const uint Damage;

    //The Missile's size
    static const int pixelWidth;
    static const int pixelHeight;
};

#endif // MISSILE_H
