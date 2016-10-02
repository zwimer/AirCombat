#include <QTimer>
#include <QApplication>
#include <QGraphicsScene>
#include <QgraphicsView>
#include <QGraphicsRectItem>

#include <Player.hpp>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //Create a scene
    QGraphicsScene *theScene = new QGraphicsScene();

    //Create a player
    Player *P1 = new Player();

    //Make a new rect starting at (0,0) that is (100,100) pixels
    P1->setRect(0,0,100,100);

    //Add player to the scene
    theScene->addItem(P1);

    //add a view
    QGraphicsView *theWindow = new QGraphicsView(theScene);

    //Prevent scrolling
    theWindow->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    theWindow->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //Define the window size
    theWindow->setFixedSize(800,600);

    //Lock the scene in place in the window
    theScene->setSceneRect(0,0,800,600);

    //Set the starting location of the player
    P1->setPos(theWindow->width()/2, theWindow->height() - P1->rect().height());

    //Make the scene visible
    theWindow->show();

    //Spawn enemys every 2 seconds
    QTimer *t = new QTimer();
    QObject::connect(t, SIGNAL(timeout()), P1, SLOT(spawn()));
    t->start(2000);

    //Finish the program
    return a.exec();
}
