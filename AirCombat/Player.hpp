#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsRectItem>


class Player : public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:

    //Constructor
    Player();

    //Allows the player to move
    void keyPressEvent(QKeyEvent *e);

public slots:
    void spawn();

private:


};

#endif // PLAYER_H
