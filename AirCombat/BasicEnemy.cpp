#include "BasicEnemy.hpp"

//BasicEnemy's stats
const uint BasicEnemy::Speed = 2;
const uint BasicEnemy::Health = 4;
const uint BasicEnemy::ScoreValue = 1;

//BasicEnemy's size
const uint BasicEnemy::Width = 158;
const uint BasicEnemy::Height = 100;


//Constructor
BasicEnemy::BasicEnemy() : Enemy(Speed, Health) {

    //Draw the enemy
    setPixmap(QPixmap(":/images/images/BasicEnemy.png"));
}


//Redraw the enemy if needed
void BasicEnemy::healthChanged(uint h)
{ if (h <= Health/2) setPixmap(QPixmap(":/images/images/BasicEnemyInjured.png")); }

//Return the enemy's width
inline uint BasicEnemy::getWidth() const { return Width; }

//Return the enemy's height
inline uint BasicEnemy::getHeight() const { return Height; }

//Return the how many points the enemy is worth
uint BasicEnemy::getScoreValue() const { return ScoreValue; }
