#include "Game.hpp"

//Game constructor
Game::Game(QWidget *parent) {

	//Create a scene and define it's size
	QGraphicsScene *theScene = new QGraphicsScene();
	theScene->setSceneRect(0,0,800,600);

	//Create and setup the window
	QGraphicsView *theWindow = new QGraphicsView(theScene);
	theWindow->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	theWindow->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	theWindow->setFixedSize(800,600);
	
	//Create a player, and center him
	Player *P1 = new Player();
	P1->setRect(0,0,100,100);
	P1->setPos(theWindow->width()/2, theWindow->height() - P1->rect().height());
	theScene->addItem(P1);

	//Spawn enemys every 2 seconds
	QTimer *t = new QTimer();
	QObject::connect(t, SIGNAL(timeout()), P1, SLOT(spawn()));
	t->start(2000);

	//Make the scene visible
	theWindow->show();
}
