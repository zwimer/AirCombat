#ifndef BOSSENEMY_H
#define BOSSENEMY_H

#include "Enemy.hpp"
#include "Shooter.hpp"
#include "AbstractTurret.hpp"

//A dangerous enemy
class BossEnemy : public Enemy, public Shooter {
public:

    //Construtor
    BossEnemy();

    //Deconstructor
    ~BossEnemy();

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
    static const uint ReloadTime;

    //Size of enemy
    static const uint Width;
    static const uint Height;
};

#endif // BossENEMY_H
