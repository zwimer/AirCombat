#ifdef GUNNERENEMY_H
#define GUNNERENEMY_H

#include "Enemy.hpp"
#include "Shooter.hpp"

//A basic enemy
class GunnerEnemy : public Enemy, public Shooter {
public:

    //Construtor
    GunnerEnemy();

    //Return the enemy's size
    inline uint getWidth() const;
    inline uint getHeight() const;

private:

    //Returns stats
    uint getScoreValue() const;

    //Redraw the enemy if needed
    void healthChanged(uint h);

    //Stats
    static const uint Speed;
    static const uint Health;
    static const uint ScoreValue;

    //Size of enemy
    static const uint Width;
    static const uint Height;
};

#endif // GUNNERENEMY_H
