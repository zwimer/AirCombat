#ifndef ENEMY_H
#define ENEMY_H

#include "Game.hpp"
#include "AutoMove.hpp"

//Note: must first inheret from QObject, THEN from ...
class Enemy : public AutoMove {
public:

    //Constructor
    Enemy()=delete;
    Enemy(uint s);

    //Virtual methods
    virtual inline uint getSpeed() const = 0;

protected:

    //Inherited pure virtual methods
    void afterMove();
    bool beforeMove();

public slots:

    //Move's the enemy
    void move();
};




#endif // ENEMY_H
