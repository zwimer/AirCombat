#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsRectItem>

//Note: must first inheret from QObject, THEN from ...
class Enemy : public QObject, public QGraphicsRectItem {
    Q_OBJECT;
public:
    Enemy();

public slots:
    void move();

};




#endif // ENEMY_H
