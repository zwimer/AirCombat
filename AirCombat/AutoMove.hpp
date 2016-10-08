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

    //To be implemented by derived classes
    virtual void afterMove()=0;

    //Returns false if the move should be skipped
    virtual bool beforeMove()=0;

private:

    //Representation
    //Note, positive, means move down
    const int speed;

};

#endif // MOVEABLE_H
