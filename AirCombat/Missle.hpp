#ifndef MISSLE_H
#define MISSLE_H

#include "Projectile.hpp"

//Forward declerations
class Shooter;

//A missle
class Missle : public Projectile {
public:

    //Constructor
    Missle();

    //Get the Missle's size
    int getHeight() const;
    int getWidth() const;

private:

    //The Missle's stats
    static const uint Speed;
    static const uint Damage;

    //The Missle's size
    static const int pixelWidth;
    static const int pixelHeight;
};

#endif // MISSLE_H
