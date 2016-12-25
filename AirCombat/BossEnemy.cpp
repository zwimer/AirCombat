#include "BossEnemy.hpp"
#include "Turret.hpp"
#include "Missile.hpp"

//BossEnemy's stats
const uint BossEnemy::Speed = 20;
const uint BossEnemy::Health = 200;
const uint BossEnemy::ScoreValue = 100;
const uint BossEnemy::ReloadTime = 2500;

//BossEnemy's size
const uint BossEnemy::Width = 150;
const uint BossEnemy::Height = 206;


//Constructor
BossEnemy::BossEnemy() : Enemy(Speed, Health),
    Left(new Turret<Missile>(this, 0, 0, ReloadTime, true)),
    Right(new Turret<Missile>(this, Width, 0, ReloadTime, true)) {

    //Draw the enemy
    setPixmap(QPixmap(":/images/images/BossEnemy.png"));
}

//Deconstructor
BossEnemy::~BossEnemy() {
    delete Left;
    delete Right;
}

//To satisfy the compiler
void BossEnemy::healthChanged(uint) {}

//Get location
int BossEnemy::getX() const { return x(); }
int BossEnemy::getY() const { return y(); }

//Return the enemy's size
inline uint BossEnemy::getWidth() const { return Width; }
inline uint BossEnemy::getHeight() const { return Height; }

//Return the how many points the enemy is worth
uint BossEnemy::getScoreValue() const { return ScoreValue; }
