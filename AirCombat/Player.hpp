#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QKeyEvent>
#include <QGraphicsRectItem>


//Note: must first inheret from QObject, THEN from ...
class Player : public QObject, public QGraphicsRectItem {
    Q_OBJECT;
public:

    //Constructor
    Player();

    //Allows the player to move
    void keyPressEvent(QKeyEvent *e);


public slots:
    void spawn();

private:


};

#endif
