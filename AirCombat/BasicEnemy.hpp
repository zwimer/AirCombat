#ifndef BASICENEMY_H
#define BASICENEMY_H

#include "Enemy.hpp"

//A basic enemy
class BasicEnemy : public Enemy {
public:

    //Construtor
    BasicEnemy();

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

    //Size of basic enemy
    static const uint Width;
    static const uint Height;
};

#endif // BASICENEMY_H
