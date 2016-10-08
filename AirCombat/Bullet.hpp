#ifndef BULLET_H
#define BULLET_H

#include "Projectile.hpp"

//Forward declerations
class Shooter;

//A Bullet
class Bullet : public Projectile {
public:

    //Constructor
    Bullet();

    //Get the Bullet's height
    int getHeight() const;

    //Set Bullet's starting position
    void setPosition(Shooter *Owner);

private:

    //The Bullet's stats
    static const uint Speed;
    static const uint Damage;

    //The Bullet's size
    static const int pixelWidth;
    static const int pixelHeight;
};

#endif
