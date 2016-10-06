#ifndef SOUND_H
#define SOUND_H

#include "SoundManager.hpp"

#include <QMediaPlayer>

//A class used for playing non-music sounds
class Sound : public QObject {
    Q_OBJECT
private:

    //Constructor
    Sound()=delete;
    Sound(const char* s);

    //A play function
    void play();

    //Allow SoundManager to make sounds
    friend void SoundManager::newSound(const char* n);

    //Representation
    QMediaPlayer *p;

public slots:
    //private:
    //Finish playing
    void Finish();
};

#endif // SOUND_H
