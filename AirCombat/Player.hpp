#ifndef PLAYER_H
#define PLAYER_H

#include <Turret.hpp>                                                         //CHANGE

#include "Health.hpp"
#include <QObject>
#include <QPointF>
#include <QKeyEvent>
#include <QGraphicsView>
#include <QGraphicsRectItem>

#include "Shooter.hpp"


#include "Bullet.hpp"           //DELETE;

//The player
class Player : public Shooter {
public:

    //Constructor
    Player(QGraphicsView *theWindow);
    ~Player();

    //Allows the player to move
    void mouseMoved(QPointF p);
    void keyPressEvent(QKeyEvent *e);

    //Returns the size of the player
    uint getWidth() const;
    uint getHeight() const;

    //Wing turrets
    Turret *WingTurretL;
    Turret *WingTurretR;

    //Representation
    Health *health;

private:

    //Default health
    static const int DefaultHealth;

    //Size
    static const int pixelWidth;
    static const int pixelHeight;

    //Move Speed
    static const int MoveSpeed;
};

#endif
