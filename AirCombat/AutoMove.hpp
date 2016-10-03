#ifndef AUTOMOVE_H
#define AUTOMOVE_H

#include <QObject>
#include <QGraphicsRectItem>

class AutoMove : public QObject, public QGraphicsRectItem {
    Q_OBJECT;
public:

    //Constructor
    AutoMove()=delete;
    AutoMove(int s);

public slots:

    //Move
    void move();

protected:

    //Returns speed
    int getSpeed() const;

    //To be implemented by derived classes
    virtual void afterMove()=0;
    virtual void beforeMove()=0;

private:

    //Note, if this is positive, it moves down the screen
    const int speed;

};

#endif // MOVEABLE_H
