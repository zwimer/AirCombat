#include "FastEnemy.hpp"


//FastEnemy's stats
const uint FastEnemy::Speed = 80;
const uint FastEnemy::Health = 20;
const uint FastEnemy::ScoreValue = 5;

//FastEnemy's size
const uint FastEnemy::Width = 75;
const uint FastEnemy::Height = 152;


//Constructor
FastEnemy::FastEnemy() : Enemy(Speed, Health) {

    //Draw the enemy
    setPixmap(QPixmap(":/images/images/FastEnemy.png"));
}

//Return the enemy's size
inline uint FastEnemy::getWidth() const { return Width; }
inline uint FastEnemy::getHeight() const { return Height; }

//Return the how many points the enemy is worth
uint FastEnemy::getScoreValue() const { return ScoreValue; }
