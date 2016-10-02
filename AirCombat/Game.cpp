#include "Game.hpp"

#include <QTimer>
#include <QGraphicsScene>
#include <QgraphicsView>
#include <QGraphicsRectItem>

//Game constructor
Game::Game(QWidget *parent) {

	//Create a scene and define it's size
    theScene = new QGraphicsScene();
	theScene->setSceneRect(0,0,800,600);

	//Create and setup the window
	QGraphicsView *theWindow = new QGraphicsView(theScene);
	theWindow->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	theWindow->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	theWindow->setFixedSize(800,600);
	
	//Create a player, and center him
    P1 = new Player();
	P1->setRect(0,0,100,100);
	P1->setPos(theWindow->width()/2, theWindow->height() - P1->rect().height());
	theScene->addItem(P1);

    //Create a new score and health
    theScore = new Score();
    theScene->addItem(theScore);
    P1Health = new Health();
    P1Health->setPos(P1Health->x(), P1Health->y()+25);
    theScene->addItem(P1Health);

	//Spawn enemys every 2 seconds
	QTimer *t = new QTimer();
	QObject::connect(t, SIGNAL(timeout()), P1, SLOT(spawn()));
	t->start(2000);

	//Make the scene visible
	theWindow->show();
}
