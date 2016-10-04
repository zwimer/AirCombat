#include "BasicEnemy.hpp"
#include "Health.hpp"
#include "Game.hpp"

#include <QGraphicsScene>

//BasicEnemy's move speed
const uint BasicEnemy::Speed = 4;

//BasicEnemy's size
const uint BasicEnemy::Height = 100;
const uint BasicEnemy::Width = 158; //100


//Constructor
BasicEnemy::BasicEnemy() : Enemy(getSpeed()) {

    //Draw the enemy
    setPixmap(QPixmap(":/images/images/BasicEnemy.png"));
}

//Return the enemy's width
inline uint BasicEnemy::getWidth() const {
    return BasicEnemy::Width;
}

//Return the enemy's height
inline uint BasicEnemy::getHeight() const {
    return BasicEnemy::Height;
}

//Returns speed
inline uint BasicEnemy::getSpeed() const { return (uint)Speed; }
