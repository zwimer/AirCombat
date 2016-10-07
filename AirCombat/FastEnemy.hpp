#ifndef FASTENEMY_H
#define FASTENEMY_H

#include "Enemy.hpp"

//A basic enemy
class FastEnemy : public Enemy {
public:

    //Construtor
    FastEnemy();

    //Returns stats
    uint getScoreValue() const;

    //Return the enemy's size
    inline uint getWidth() const;
    inline uint getHeight() const;

private:

    //Stats
    static const uint Speed;
    static const uint ScoreValue;

    //Size of basic enemy
    static const uint Width;
    static const uint Height;
};

#endif // FASTENEMY_H
