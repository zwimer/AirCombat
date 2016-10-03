#ifndef AUTOMOVE_H
#define AUTOMOVE_H

#include "main.hpp"
#include <QObject>

class AutoMove : public QObject {
    Q_OBJECT;
public:
    AutoMove(uint s = 0);

public slots:
    virtual void move()=0;

protected:

    //Returns speed
    uint getSpeed() const;

private:
    const uint speed;

};

#endif // MOVEABLE_H
