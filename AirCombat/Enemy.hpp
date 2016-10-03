#ifndef ENEMY_H
#define ENEMY_H

#include "AutoMove.hpp"


//Note: must first inheret from QObject, THEN from ...
class Enemy : public AutoMove {
public:
    Enemy()=delete;
    Enemy(int s);

protected:
    void afterMove();
    void beforeMove();

public slots:
    void move();
};




#endif // ENEMY_H
