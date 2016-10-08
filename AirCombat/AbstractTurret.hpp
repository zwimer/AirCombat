#ifndef ABSTRACTTURRET_H
#define ABSTRACTTURRET_H

#include "main.hpp"
#include "Shooter.hpp"
#include "Projectile.hpp"

#include <QObject>
#include <QTimer>

//An AbstractTurret class
class AbstractTurret: public QObject, public Shooter {
    Q_OBJECT
protected:

    //Constructors
    AbstractTurret()=delete;
    AbstractTurret(Shooter* o, int x, int y, uint t = 0);

public:

    //Set fire rate
    void setFireRate(uint t);

public slots:

    //Shoots
    void shoot();

private:

    //The templated turret subclass
    //must make the projectile to be shot
    virtual Projectile* createProjectile() const = 0;

    //Returns the location of the turret
    int getX() const;
    int getY() const;

    //Returns the size of the turret
    uint getWidth() const;
    uint getHeight() const;

    //What the turret is on
    const Shooter *Owner;

    //To keep track of when the turret should shoot
    QTimer *timer;

    //The turret's location on Owner
    const int offsetX, offsetY;

};

#endif // AbstractTurret_H
