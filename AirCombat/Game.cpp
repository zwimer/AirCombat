#include "Game.hpp"
#include "BasicEnemy.hpp"

#include <QTimer>
#include <QGraphicsScene>
#include <QgraphicsView>
#include <QGraphicsRectItem>

//The Game's size
const uint Game::Height = 600;
const uint Game::Width = 800;

//Game constructor
Game::Game() {

	//Create a scene and define it's size
    theScene = new QGraphicsScene();
    theScene->setSceneRect(0,0,Width,Height);

	//Create and setup the window
	QGraphicsView *theWindow = new QGraphicsView(theScene);
	theWindow->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	theWindow->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    theWindow->setFixedSize(Width,Height);
	
	//Create a player, and center him
    P1 = new Player(theWindow);

    //Create a new score and health
    theScore = new Score();
    theScene->addItem(theScore);

	//Spawn enemys every 2 seconds
    QTimer *t = new QTimer();
    QObject::connect(t, SIGNAL(timeout()), this, SLOT(spawn()));
    t->start(2000);

	//Make the scene visible
	theWindow->show();
}

//Destructor
Game::~Game() { delete theScore; delete P1; delete theScene; }

//Create a new enemy and add it to the scene
void Game::spawn() {
    theScene->addItem(new BasicEnemy()); //CHANGE
}
