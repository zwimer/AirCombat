#ifndef BASICENEMY_H
#define BASICENEMY_H

#include "Enemy.hpp"

//A basic enemy
class BasicEnemy : public Enemy {
public:

    //Construtor
    BasicEnemy();

    //Returns stats
    uint getScoreValue() const;

    //Return the enemy's size
    inline uint getWidth() const;
    inline uint getHeight() const;

private:

    //Stats
    static const uint Speed;
    static const uint Health;
    static const uint ScoreValue;

    //Size of basic enemy
    static const uint Width;
    static const uint Height;
};

#endif // BASICENEMY_H
