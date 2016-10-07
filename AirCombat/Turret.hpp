#ifndef TURRET_H
#define TURRET_H

#include "main.hpp"
#include "Shooter.hpp"
#include "Projectile.hpp"

#include <QObject>


//A turret class that shoots T

class Turret : public QObject, public Shooter {
    Q_OBJECT

public:

    //Constructors
    Turret()=delete;
    Turret(Shooter* o, int x, int y, uint t = 0);

    //Set fire rate
    void setFireRate(uint t);

    int getX() const;
    int getY() const;

    uint getWidth() const;
    uint getHeight() const;

public slots:

    void shoot();

private:

    uint fireRate;
    Shooter *Owner;

    const int offsetX, offsetY;

};


#if 0
//A turret class that shoots T
template <class T>
class Turret : public QObject, public Shooter {

    //Make sure T is a projectile
    static_assert(std::is_base_of<Projectile, T>::value,
                  "T must be a projectile");

    Q_OBJECT

public:

    //Constructors
    Turret()=delete;
    Turret(Shooter* o, int x, int y, uint t = 0);

    //Set fire rate
    void setFireRate(uint t);

    uint x() const;
    uint y() const;
    uint getWidth() const;
    uint getHeight() const;

public slots:

    void fire();

private:

    uint fireRate;
    Shooter *Owner;

    const int offsetX, offsetY;

};

//CHANGE
#endif
#endif // TURRET_H
