#ifndef GUNNERENEMY_H
#define GUNNERENEMY_H

#include "Enemy.hpp"
#include "Shooter.hpp"
#include "AbstractTurret.hpp"

//A basic enemy
class GunnerEnemy : public Enemy, public Shooter {
public:

    //Construtor
    GunnerEnemy();

    //Deconstructor
    ~GunnerEnemy();

private:

    //Get location
    int getX() const;
    int getY() const;

    //Return the enemy's size
    inline uint getWidth() const;
    inline uint getHeight() const;

    //Returns stats
    uint getScoreValue() const;

    //Redraw the enemy if needed
    void healthChanged(uint h);

    //Wing turrets
    const AbstractTurret *Left;
    const AbstractTurret *Right;

    //Stats
    static const uint Speed;
    static const uint Health;
    static const uint ScoreValue;

    //Size of enemy
    static const uint Width;
    static const uint Height;
};

#endif // GUNNERENEMY_H
