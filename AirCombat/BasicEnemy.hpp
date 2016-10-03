#ifndef BASICENEMY_H
#define BASICENEMY_H

#include "Enemy.hpp"

//A basic enemy
class BasicEnemy : public Enemy {
public:
    BasicEnemy();

    //Returns speed
    inline uint getSpeed() const;

    //The speed of basic enemy
    static const uint Speed;

    //Size of basic enemy
    static const uint Height;
    static const uint Width;
};

#endif // BASICENEMY_H
