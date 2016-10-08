#include "Game.hpp"
#include "Enemy.hpp"
#include "Score.hpp"
#include "Player.hpp"
#include "SmartScene.hpp"

#include <QBrush>
#include <QTimer>
#include <QMediaPlayer>

//The Game's size
const uint Game::Height = 600;
const uint Game::Width = 800;

//Game constructor
Game::Game() {

	//Create a scene and define it's size
    theScene = new SmartScene();
    theScene->setSceneRect(0,0,Width,Height);

    //Create the background
    theScene->setBackgroundBrush(QBrush(QImage(":/images/images/Background")));

	//Create and setup the window
    theWindow = new QGraphicsView(theScene);
	theWindow->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	theWindow->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    theWindow->setFixedSize(Width,Height);

    //Allow moust tracking
    theWindow->setMouseTracking(true);

	//Create a player, and center him
    P1 = new Player(theWindow);

    //Create a new score and health
    theScore = new Score();
    theScene->addItem(theScore);

    //Spawn enemys every second
    QTimer *t = new QTimer();
    QObject::connect(t, SIGNAL(timeout()), this, SLOT(spawn()));
    t->start(500);

    //Play background music
    theMusic = new QMediaPlayer();
    theMusic->setMedia(QUrl("qrc:/sounds/sounds/Background.mp3"));
    theMusic->play();

    //Loop the music
    QObject::connect(theMusic, SIGNAL(stateChanged(QMediaPlayer::State)),
                     this, SLOT(restartMusic()));

	//Make the scene visible
	theWindow->show();
}

//Destructor
Game::~Game() { delete theScore; delete P1; delete theScene; }

//GameOver
#include <QDebug>
void Game::GameOver() {
    qDebug() << "GAME OVER: Still needs to be implemented";

}

//Create a new enemy and add it to the scene
void Game::spawn() { theScene->addItem(Enemy::spawnEnemy()); }

//If the music finishes, restart it
void Game::restartMusic() {
    if (theMusic->state() == QMediaPlayer::StoppedState)
        theMusic->play();
}
