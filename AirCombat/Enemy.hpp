#ifndef ENEMY_H
#define ENEMY_H

#include "AutoMove.hpp"

//Note: must first inheret from QObject, THEN from ...
class Enemy : public AutoMove {
public:

    //Constructor
    Enemy()=delete;
    Enemy(uint s);

    //Pure virtual methods
    virtual inline uint getSpeed() const = 0;
    virtual inline uint getWidth() const = 0;
    virtual inline uint getHeight() const = 0;

    //Override the enemy's initial position
    //If you chose to do so, override this with caution
    //Otherwise, do not implement this function!
    virtual void spawn();

    //Called by the game to spawn an enemy
    static Enemy* spawnEnemy();

protected:

    //Inherited pure virtual methods
    void afterMove();
    bool beforeMove();

public slots:

    //Move's the enemy
    void move();
};




#endif // ENEMY_H
