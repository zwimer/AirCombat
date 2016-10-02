#ifndef PLAYER_H
#define PLAYER_H

#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsRectItem>


class Player : public QGraphicsRectItem {
public:

    //Constructor
    Player();

    //Allows the player to move
    void keyPressEvent(QKeyEvent *e);


private:


};

#endif // PLAYER_H
