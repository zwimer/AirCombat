#include "BasicEnemy.hpp"
#include "Health.hpp"
#include "Game.hpp"

#include <stdlib.h>
#include <QGraphicsScene>


//BasicEnemy's move speed
const uint BasicEnemy::Speed = 10;

//BasicEnemy's size
const uint BasicEnemy::Height = 100;
const uint BasicEnemy::Width = 158; //100


//Constructor
BasicEnemy::BasicEnemy() : Enemy(getSpeed()) {

    setPixmap(QPixmap(":/images/BasicEnemy.png"));

//CHANGE
    //Randomize location
    setPos(rand()%(Game::Width - BasicEnemy::Width), -(int)BasicEnemy::Height); //CHANGE
}

//Returns speed
inline uint BasicEnemy::getSpeed() const { return (uint)Speed; }
