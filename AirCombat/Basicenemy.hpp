#ifndef BASICENEMY_H
#define BASICENEMY_H

#include <QObject>
#include <QGraphicsRectItem>

class BasicEnemy : public QObject, public QGraphicsRectItem {
    Q_OBJECT;
public:
    BasicEnemy();

public slots:
    void move();
};

#endif // BASICENEMY_H
