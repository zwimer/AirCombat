#ifndef HEALTH_H
#define HEALTH_H

#include "main.hpp"

#include <QGraphicsTextItem>

class Health : public QGraphicsTextItem{
public:

    //Constructor
    Health()=delete;
    Health(uint h, QGraphicsItem *p = NULL);

    //Setters
    void decrease(unsigned int x);

private:

    //Representation
    int health;
};

#endif // HEALTH_H
