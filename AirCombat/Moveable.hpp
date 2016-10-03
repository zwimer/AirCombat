#ifndef MOVEABLE_H
#define MOVEABLE_H

#include "main.hpp"
#include <QObject>

class Moveable : public QObject {
    Q_OBJECT;
public:
    Moveable(uint s = 0);

public slots:
    virtual void move()=0;

protected:

    //Returns speed
    uint getSpeed() const;

private:
    const uint speed;

};

#endif // MOVEABLE_H
