#include "Player.hpp"
#include "Missle.hpp"
#include "Game.hpp"

//Player's move speed
const int Player::MoveSpeed = 1;

//Set player's default health
const int Player::DefaultHealth = 3;

//Set player's size
const int Player::pixelWidth = 128;
const int Player::pixelHeight = 104;

//Constructor
Player::Player(QGraphicsView *theWindow) {

    //Make the Player's health
    health = new Health(Player::DefaultHealth);
    health->setPos(health->x(), health->y()+25);
    theWindow->scene()->addItem(health);

    //Set the player's size and starting location
    setPixmap(QPixmap(":/images/images/Player.png"));
    setPos(theWindow->width()/2, theWindow->height() - pixelHeight);

    //Add the player to the scene
    theWindow->scene()->addItem(this);

    //Make wing turrets
    WingTurretL = new Turret<Missle>(this, Player::pixelWidth/4, Player::pixelHeight/2, 3000);
    WingTurretR = new Turret<Missle>(this, 3*Player::pixelWidth/4, Player::pixelHeight/2, 3000);
}

//Destructor
Player::~Player() { delete health; }

//Returns the player's size
uint Player::getWidth() const { return Player::pixelWidth; }
uint Player::getHeight() const { return Player::pixelHeight; }

//If the mouse was moved, go to it
void Player::mouseMoved(QPointF p) {

    //Shift the points so that the
    //mouse is in the center of the player
    int Cx = (int)p.x() - pixelWidth/2;
    int Cy = (int)p.y() - pixelHeight/2;

    //If the mouse is out of bounds move it back in
    if (Cx < 0) Cx = 0;
    else if (Cx >= (int)(Game::Width-pixelWidth)) Cx = Game::Width-pixelWidth-1;
    if (Cy < 0) Cy = 0;
    else if (Cy >= (int)(Game::Height-pixelHeight)) Cy = Game::Height-pixelHeight-1;

    //Move the player
    setPos(Cx,Cy);
}
