#include "BasicEnemy.hpp"
#include "Health.hpp"
#include "Game.hpp"

//BasicEnemy's move speed
const int BasicEnemy::Speed = 10;

//Constructor
BasicEnemy::BasicEnemy() : Enemy(BasicEnemy::Speed) {

    //Set the size
    setRect(0,0,100,100);
}
