#ifndef SMARTSCENE_H
#define SMARTSCENE_H

#include <QCursor>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

//A custom QGraphicsScene
class SmartScene : public QGraphicsScene {
public:

    //Constructor
    SmartScene();

private slots:

    //Move the player
    void mouseMoveEvent(QGraphicsSceneMouseEvent *e);

    //Fire a bullet
    void mousePressEvent(QGraphicsSceneMouseEvent *);

};

#endif // SMARTSCENE_H
