#include "FastEnemy.hpp"
#include "Health.hpp"
#include "Game.hpp"

#include <QGraphicsScene>

//FastEnemy's stats
const uint FastEnemy::Speed = 8;
const uint FastEnemy::ScoreValue = 5;

//FastEnemy's size
const uint FastEnemy::Width = 75;
const uint FastEnemy::Height = 152;


//Constructor
FastEnemy::FastEnemy() : Enemy(Speed) {

    //Draw the enemy
    setPixmap(QPixmap(":/images/images/FastEnemy.png"));
}

//Return the enemy's width
inline uint FastEnemy::getWidth() const { return Width; }

//Return the enemy's height
inline uint FastEnemy::getHeight() const { return Height; }

//Return the how many points the enemy is worth
uint FastEnemy::getScoreValue() const { return ScoreValue; }