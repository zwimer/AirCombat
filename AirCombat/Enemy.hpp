#ifndef ENEMY_H
#define ENEMY_H

#include "Moveable.hpp"
#include <QGraphicsRectItem>


//Note: must first inheret from QObject, THEN from ...
class Enemy : public Moveable, public QGraphicsRectItem {
public:
    Enemy();

public slots:
    void move();
};




#endif // ENEMY_H
