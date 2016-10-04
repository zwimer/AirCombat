#ifndef SOUNDPLAYER_H
#define SOUNDPLAYER_H

#include <QObject>
#include <QMediaPlayer>

//Forward declerations
class Game;

//Used to play sounds and clean up
class soundPlayer : public QObject, public QMediaPlayer {
    QObject;
public:

    //Constructor
    soundPlayer(const char* Which);

public slots:

    //Much like a destructor
    //Finishes playing the sound when needed
    void finishSound();
};

#endif // SOUNDPLAYER_H
