#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include "AutoMove.hpp"
#include <QObject>

//Note: must first inheret from QObject, THEN from ...
class Enemy : public AutoMove {
public:

    //Constructor
    Enemy()=delete;
    Enemy(int s);



protected:

    //Inherited pure virtual methods
    void afterMove();
    bool beforeMove();

public slots:

    //Move's the enemy
    void move();
};




#endif // ENEMY_H
