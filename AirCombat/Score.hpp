#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

//A class to represnet a score
class Score : public QGraphicsTextItem {
public:

    //Constructor
    Score(QGraphicsItem *parent = NULL);

    //Setters
    void increase(unsigned int);

private:
    int score;
};

#endif // SCORE_H
