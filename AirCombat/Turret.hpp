#ifndef TURRET_H
#define TURRET_H

#include "main.hpp"
#include "Shooter.hpp"
#include "Projectile.hpp"

#include <QObject>
#include <QTimer>

//A turret class that shoots T
class Turret: public QObject, public Shooter {
    Q_OBJECT
public:

    //Constructors
    Turret()=delete;
    Turret(Shooter* o, int x, int y, uint t = 0);

    //Set fire rate
    void setFireRate(uint t);

    //Returns the location of the turret
    int getX() const;
    int getY() const;

    //Returns the size of the turret
    uint getWidth() const;
    uint getHeight() const;

public slots:

    //Shoots
    void shoot();

private:

    //What the turret is on
    const Shooter *Owner;

    //To keep track of when the turret should shoot
    QTimer *timer;

    //The turret's location on Owner
    const int offsetX, offsetY;

};

#endif // TURRET_H
