#include "Player.hpp"
#include "BasicEnemy.hpp"
#include "Bullet.hpp"
#include "Game.hpp"

//Set player's default health
const int Player::DefaultHealth = 3;

//Constructor
Player::Player(QGraphicsScene *theScene) {

    //Make this player focusable
    this->setFlag(QGraphicsItem::ItemIsFocusable);

    //Make this the focus item
    this->setFocus();

    //Make the Player's health
    health = new Health(Player::DefaultHealth);
    health->setPos(health->x(), health->y()+25);
    theScene->addItem(health);
}

//Destructor
Player::~Player() {
    delete health;
}

//If a button was pressed
void Player::keyPressEvent(QKeyEvent *e) {

    //Move left
    if (e->key() == Qt::Key_Left) {
        if (pos().x() > 0)
             setPos(x()-25,y());
    }

    //Move right
    else if (e->key() == Qt::Key_Right) {
        if (pos().x() + 100 < 800)    //CHANGE
            setPos(x()+25,y());
    }

    //Shoot
    else if (e->key() == Qt::Key_Space) { fire(new Bullet()); }
}

//Create a new enemy and add him to the scene
void Player::spawn() {

    Enemy *e = new BasicEnemy();   //CHANGE
    scene()->addItem(e);
}
