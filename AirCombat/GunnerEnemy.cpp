#if 0
#include "GunnerEnemy.hpp"

//GunnerEnemy's stats
const uint GunnerEnemy::Speed = 10;
const uint GunnerEnemy::Health = 10;
const uint GunnerEnemy::ScoreValue = 8;

//GunnerEnemy's size
const uint GunnerEnemy::Width = 158;
const uint GunnerEnemy::Height = 100;


//Constructor
GunnerEnemy::GunnerEnemy() : Enemy(Speed, Health) {

    //Draw the enemy
    setPixmap(QPixmap(":/images/images/GunnerEnemy.png"));
}


//To satisfy the compiler
void GunnerEnemy::healthChanged(uint h) {}

//Return the enemy's width
inline uint GunnerEnemy::getWidth() const { return Width; }

//Return the enemy's height
inline uint GunnerEnemy::getHeight() const { return Height; }

//Return the how many points the enemy is worth
uint GunnerEnemy::getScoreValue() const { return ScoreValue; }
#endif
