#include "BasicEnemy.hpp"
#include "Health.hpp"
#include "Game.hpp"

#include <stdlib.h>
#include <QGraphicsScene>


//BasicEnemy's move speed
const uint BasicEnemy::Speed = 10;

//BasicEnemy's size
const uint BasicEnemy::Height = 100;
const uint BasicEnemy::Width = 100;


//Constructor
BasicEnemy::BasicEnemy() : Enemy(getSpeed()) {

    //Set the size
    setRect(0,0,100,100);


//CHANGE
    //Randomize location
    setPos(rand()%(Game::Width - BasicEnemy::Width), 0); //CHANGE
}

//Returns speed
inline uint BasicEnemy::getSpeed() const { return (uint)Speed; }
