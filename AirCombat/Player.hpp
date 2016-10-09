#ifndef PLAYER_H
#define PLAYER_H

#include <Turret.hpp>

#include "Health.hpp"
#include <QObject>
#include <QPointF>
#include <QKeyEvent>
#include <QGraphicsView>
#include <QGraphicsRectItem>

#include "Shooter.hpp"


#include "Bullet.hpp"           //DELETE;

//The player
class Player : public Shooter, public QGraphicsPixmapItem {
public:

    //Constructor
    Player() = delete;
    Player(QGraphicsView *theWindow);
    ~Player();

    //Allows the player to move
    void mouseMoved(QPointF p);


    int getX() const ;
    int getY() const ;

    //Player's health
    Health *health;

private:

    //Returns the size of the player
    uint getWidth() const;
    uint getHeight() const;

    //Wing turrets
    AbstractTurret *WingTurretL;
    AbstractTurret *WingTurretR;

    //Default health
    static const int DefaultHealth;

    //Size
    static const int pixelWidth;
    static const int pixelHeight;

    //Move Speed
    static const int MoveSpeed;
};

#endif
