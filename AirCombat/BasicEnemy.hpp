#ifndef BASICENEMY_H
#define BASICENEMY_H

#include "Enemy.hpp"

//A basic enemy
class BasicEnemy : public Enemy {
public:
    BasicEnemy();

    //The speed of basic enemy
    static const int Speed;
};

#endif // BASICENEMY_H
