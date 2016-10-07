#ifndef PLAYER_H
#define PLAYER_H

#include <Turret.hpp>                                                         //CHANGE

#include "Health.hpp"
#include <QObject>
#include <QKeyEvent>
#include <QGraphicsView>
#include <QGraphicsRectItem>

#include "Shooter.hpp"


#include "Bullet.hpp"           //DELETE;

//Note: must first inheret from QObject, THEN from ...
class Player : public Shooter {
public:

    //Constructor
    Player(QGraphicsView *theWindow);
    ~Player();

    //Allows the player to move
    void keyPressEvent(QKeyEvent *e);

    //Returns the size of the player
    uint getWidth() const;
    uint getHeight() const;


    //CHANGE
        Turret * t;
    //    Turret<Bullet> * t;

    //CHANGE

    //Representation
    Health *health;

private:

    //Default health
    static const int DefaultHealth;

    //Size
    static const int pixelWidth;
    static const int pixelHeight;
};

#endif
