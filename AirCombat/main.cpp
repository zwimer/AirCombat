#include <QApplication>
#include <QGraphicsScene>
#include <QgraphicsView>
#include <QGraphicsRectItem>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //create a scene
    QGraphicsScene *theScene = new QGraphicsScene();

    //create a player
    QGraphicsRectItem * P1 = new QGraphicsRectItem();

    //Make a new rect starting at (0,0) that is (100,100) pixels
    P1->setRect(0,0,100,100);

    //Add player to the scene
    theScene->addItem(P1);

    //add a view
    QGraphicsView * theWindow = new QGraphicsView(theScene);

    //Make the scene visible
    theWindow->show();


    return a.exec();
}
