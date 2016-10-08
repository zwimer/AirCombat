#ifndef FASTENEMY_H
#define FASTENEMY_H

#include "Enemy.hpp"

//A basic enemy
class FastEnemy : public Enemy {
public:

    //Construtor
    FastEnemy();

    //Return the enemy's size
    inline uint getWidth() const;
    inline uint getHeight() const;

private:

    //Returns stats
    uint getScoreValue() const;

    //Stats
    static const uint Speed;
    static const uint Health;
    static const uint ScoreValue;

    //Size of basic enemy
    static const uint Width;
    static const uint Height;
};

#endif // FASTENEMY_H
