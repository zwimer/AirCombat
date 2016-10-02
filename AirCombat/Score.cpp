#include "Score.hpp"

#include <QFont>

//Constructor
Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent) {

    //Initalize the score
    score = 0;

    //Draw the score
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));
}

//Increase the score by x
void Score::increase(unsigned int x) {

    //Increase the score
    score += x;

    //Redraw the score
    setPlainText(QString("Score: ") + QString::number(score));
}
