#ifndef TURRET_H
#define TURRET_H

#include "Shooter.hpp"
#include "Projectile.hpp"
#include "AbstractTurret.hpp"

//A turret class that allows a
//QObject's sub class to be templated
template <class T> class Turret : public AbstractTurret {

    //Assert that T is a subtype of Projectile
    static_assert( std::is_base_of<Projectile, T>::value,
                   "T must be a Projectile" );

public:

    //Delete default constructor
    Turret()=delete;

    Turret(Shooter* o, int x, int y, uint t, bool r = false);

    //Make the projectile to be shot
    Projectile* createProjectile() const ;

private:

    //Representation
    bool reverseTurret;
};


//Constructor
template <class T>
Turret<T>::Turret(Shooter* o, int x, int y, uint t, bool r)
: AbstractTurret(o, x, y, t), reverseTurret(r) {}

//Make the projectile
template <class T> Projectile* Turret<T>::createProjectile() const {
    return new T(this, reverseTurret);
}

#endif // TURRET_H
