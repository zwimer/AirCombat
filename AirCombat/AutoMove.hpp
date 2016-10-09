#ifndef AUTOMOVE_H
#define AUTOMOVE_H

#include <QObject>
#include <QGraphicsPixmapItem>

//An abstract class moves autonomously
//Note, must inheret from QObject first!
class AutoMove : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:

    //Constructor
    AutoMove()=delete;
    AutoMove(int s);

private slots:

    //Move
    void move();

protected:

    //Note, because of speed scaling, an AutoMove
    //will not move every turn unless s is divisible
    //by SpeedReductionFactor. However, other AutoMoves
    //may, so keep this in mind while implementing these

    //This will be called before every turn!
    //Returns false if the turn should be skipped
    virtual bool beforeTurn()=0;

    //This will be called after every move, not turn!
    virtual void afterMove()=0;

private:

    //A small function that scales down what
    //by the gcd of s and SpeedReductionFactor
    inline int scaleDown(int what, int s);

    //Representation
    int TurnNumber;
    const int speed;
    const int MoveTurn;

    //Allows for more precision in speeds
    //without reduction in video quality
    //This number directly scales both precision
    //Ie, 10 = 10 * precieion and 10 * overhead
    static const int SpeedReductionFactor;
};

#endif // MOVEABLE_H
