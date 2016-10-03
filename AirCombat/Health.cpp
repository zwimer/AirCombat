#include "Health.hpp"

#include <QFont>

//Constructor
Health::Health(uint h, QGraphicsItem *p) : QGraphicsTextItem(p) {

    //Initalize health
    health = h; //CHANGE

    //Draw the text
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
}

//Decrease health
void Health::decrease(unsigned int x) {

    //Decrease health
    health -= (int)x;

    //Redraw the text
    setPlainText(QString("Health: ") + QString::number(health));
}
