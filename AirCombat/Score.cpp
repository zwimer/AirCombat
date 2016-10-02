#include "Score.hpp"

Score::Score(QGraphicsTextItem *parent) : QGraphicsTextItem(parent) {


    score = 0;

    //Draw the score
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));
}

void Score::increase(unsigned int x) {
    score += x;
}
void Score::decrease(unsigned int x) {
    score -= (int)x;
}
