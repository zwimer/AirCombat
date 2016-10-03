#ifndef HEALTH_H
#define HEALTH_H

#include "main.hpp"
#include <QGraphicsTextItem>

class Health : public QGraphicsTextItem{
public:
    Health(uint h, QGraphicsItem *p = NULL);

    //Setters
    void decrease(unsigned int x);

    //CONST EVERYTHING WHEN CHANGE

private:
    int health;
};

#endif // HEALTH_H
