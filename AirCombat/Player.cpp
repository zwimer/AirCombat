#include "Player.hpp"
#include "BasicEnemy.hpp"
#include "Bullet.hpp"
#include "Game.hpp"

#include <QGraphicsScene>


//Set player's default health
const int Player::DefaultHealth = 3;

//Set player's size
const int Player::pixelWidth = 128;
const int Player::pixelHeight = 104;

//Constructor
Player::Player(QGraphicsView *theWindow) {

    //Focus the player
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();

    //Make the Player's health
    health = new Health(Player::DefaultHealth);
    health->setPos(health->x(), health->y()+25);
    theWindow->scene()->addItem(health);

    //Set the player's size and location
    setPixmap(QPixmap(":/images/images/Player.png"));
    setPos(theWindow->width()/2, theWindow->height() - pixelHeight);

    //Add the player to the scene
    theWindow->scene()->addItem(this);

    //Make wing turrets
    WingTurretL = new Turret(this, Player::pixelWidth/4, Player::pixelHeight/2, 3000);
    WingTurretR = new Turret(this, 3*Player::pixelWidth/4, Player::pixelHeight/2, 3000);
}

//Destructor
Player::~Player() { delete health; }

//Returns the player's size
uint Player::getWidth() const { return Player::pixelWidth; }
uint Player::getHeight() const { return Player::pixelHeight; }

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
    else if (e->key() == Qt::Key_Space) { fire(new Bullet()); } //CHANGE
}
