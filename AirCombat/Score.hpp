#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score : public QGraphicsTextItem {
public:
    Score(QGraphicsItem *parent = NULL);
    void increase(unsigned int);
    void decrease(unsigned int);
    int getScore();

private:
    int score;
};

#endif // SCORE_H
