#ifndef MISSLE_H
#define MISSLE_H

#include "Projectile.hpp"

//Forward declerations
class Shooter;

//Note: must first inheret from QObject, THEN from ...
class Missle : public Projectile {
public:

    //Constructor
    Missle();

    //Get the Missle's height
    int getHeight() const;

    //Set Missle's starting position
    void setPosition(Shooter *Owner);

private:

    //The Missle's speed
    static const uint Speed;

    //The Missle's size
    static const int pixelWidth;
    static const int pixelHeight;
};

#endif // MISSLE_H
