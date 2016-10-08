#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QgraphicsView>
#include <QGraphicsScene>

//Forward declerations
class Score;
class Player;
#include <SmartScene.hpp>
class SmartScene;
class QMediaPlayer;

class Game : public QObject {
    Q_OBJECT
public:

    //Constructor
    Game();

    //Destructor
    ~Game();

    //Game over
    void GameOver();

    //Representation
    Player *P1;
    Score *theScore;
    SmartScene *theScene;
    QGraphicsView *theWindow;

    //Static const variables
    static const uint Height;
    static const uint Width;

public slots:

    //Spawn enemies
    void spawn();

    //Loop music
    void restartMusic();

private:

    //Music
    QMediaPlayer *theMusic;
};

//Global variable
extern Game *theGame;

#endif // GAME_H
