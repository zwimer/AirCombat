#ifndef BULLET_H
#define BULLET_H

#include "Projectile.hpp"

//Forward declerations
class Shooter;

//A Bullet
class Bullet : public Projectile {
public:

    //Constructor
    Bullet() = delete;
    Bullet(const Shooter *o, bool r = false);

private:

    //Get the Bullet's size
    int getHeight() const;
    int getWidth() const;

    //The Bullet's stats
    static const uint Speed;
    static const uint Damage;

    //The Bullet's size
    static const int pixelWidth;
    static const int pixelHeight;
};

#endif
