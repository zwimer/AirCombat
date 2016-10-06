#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QGraphicsScene>

//Forward declerations
class Score;
class Player;
class QMediaPlayer;

class Game : public QObject {
    Q_OBJECT
public:

    //Constructor
    Game();

    //Destructor
    ~Game();

    //Representation
    Player *P1;
    Score *theScore;
    QGraphicsScene *theScene;

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
