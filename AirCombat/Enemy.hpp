#ifndef ENEMY_H
#define ENEMY_H

#include "AutoMove.hpp"
#include <QGraphicsRectItem>


//Note: must first inheret from QObject, THEN from ...
class Enemy : public AutoMove, public QGraphicsRectItem {
public:
    Enemy();

public slots:
    void move();
};




#endif // ENEMY_H
