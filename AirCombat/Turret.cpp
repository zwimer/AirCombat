#include "Turret.hpp"
#include "Bullet.hpp"

#include <QTimer>

#if 1
Turret::Turret(Shooter* o, int x, int y, uint t) : offsetX(x), offsetY(y) {

    fireRate = t;
    Owner = o;

    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()),
                     this, SLOT(shoot()));
    if (t) timer->start(t);

}

//Set fire rate
void Turret::setFireRate(uint t) { fireRate = t; }

int Turret::getX() const { return Owner->x()+offsetX; }
int Turret::getY() const { return Owner->y()+offsetY; }

uint Turret::getWidth() const { return 0; } //CHANGE
uint Turret::getHeight() const { return 0; }

#include <QDebug>
void Turret::shoot() {
    qDebug() << "I WAS CALLED!!!";
    fire(new Bullet(), this);
}
#endif
#if 0
template<class T>
Turret<T>::Turret(Shooter* o, int x, int y, uint t) : offsetX(x), offsetY(y) {


    fireRate = t;
    Owner = o;

}

//Set fire rate
template<class T> void Turret<T>::setFireRate(uint t) { fireRate = t; }

template<class T> uint Turret<T>::x() const { return Owner->x()+offsetX; }
template<class T> uint Turret<T>::y() const { return Owner->y()+offsetY; }

template<class T> uint Turret<T>::getWidth() const { return 0; } //CHANGE
template<class T> uint Turret<T>::getHeight() const { return 0; }

template<class T> void Turret<T>::fire() {

}
#endif
