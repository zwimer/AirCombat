#include "GunnerEnemy.hpp"
#include "Turret.hpp"
#include "Bullet.hpp"

//GunnerEnemy's stats
const uint GunnerEnemy::Speed = 10;
const uint GunnerEnemy::Health = 10;
const uint GunnerEnemy::ScoreValue = 20;
const uint GunnerEnemy::ReloadTime = 2000;

//GunnerEnemy's size
const uint GunnerEnemy::Width = 100;
const uint GunnerEnemy::Height = 164;


//Constructor
GunnerEnemy::GunnerEnemy() : Enemy(Speed, Health),
    Left(new Turret<Bullet>(this, 0, 0, ReloadTime, true)),
    Right(new Turret<Bullet>(this, Width, 0, ReloadTime, true)) {

    //Draw the enemy
    setPixmap(QPixmap(":/images/images/GunnerEnemy.png"));
}

//Deconstructor
GunnerEnemy::~GunnerEnemy() {
    delete Left;
    delete Right;
}

//To satisfy the compiler
void GunnerEnemy::healthChanged(uint) {}

//Get location
int GunnerEnemy::getX() const { return x(); }
int GunnerEnemy::getY() const { return y(); }

//Return the enemy's size
inline uint GunnerEnemy::getWidth() const { return Width; }
inline uint GunnerEnemy::getHeight() const { return Height; }

//Return the how many points the enemy is worth
uint GunnerEnemy::getScoreValue() const { return ScoreValue; }
