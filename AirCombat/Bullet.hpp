#ifndef BULLET_H
#define BULLET_H

#include "Projectile.hpp"
#include <QObject>
#include <QGraphicsRectItem>

//Note: must first inheret from QObject, THEN from ...
class Bullet : public QObject, public QGraphicsRectItem {
    Q_OBJECT;
public:
    Bullet();

public slots:
    void move();

};



#endif
