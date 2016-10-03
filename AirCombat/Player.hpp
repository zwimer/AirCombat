#ifndef PLAYER_H
#define PLAYER_H

#include "Health.hpp"
#include <QObject>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsRectItem>

#include "Shooter.hpp"

//Note: must first inheret from QObject, THEN from ...
class Player : public QObject, /*public QGraphicsRectItem*/ public Shooter {
    Q_OBJECT;
public:

    //Constructor
    Player(QGraphicsScene *theScene);
    ~Player();

    //Allows the player to move
    void keyPressEvent(QKeyEvent *e);

    //The Player's health
    Health *health;

public slots:
    void spawn();

private:

    //Default health
    static const int DefaultHealth;
};

#endif
