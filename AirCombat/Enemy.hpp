#ifndef ENEMY_H
#define ENEMY_H

#include "AutoMove.hpp"

//An abstract enemy class
class Enemy : public AutoMove {
public:

    //Constructor
    Enemy()=delete;
    Enemy(uint s, uint h);

    //Decrease enemy's health
    //Returns true if the enemy has been destroyed
    bool decreaseHealth(uint d);

    //Get enemy's stats
    virtual uint getScoreValue() const = 0;

    //Get enemy's size
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

private:

    //Check if the plane was hit
    bool checkHit();

    //Representation
    int health;
};




#endif // ENEMY_H
