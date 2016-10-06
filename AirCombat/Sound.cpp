#include "Sound.hpp"

//Constructor
Sound::Sound(const char* s) {

    //Create a new media player
    p = new QMediaPlayer();

    //Set the media
    p->setMedia(QUrl(s));

    //Connect this sounds to the remove function
    QObject::connect(p, SIGNAL(stateChanged(QMediaPlayer::State)),
                     this, SLOT(Finish()));
}

//Play the sound
void Sound::play() { p->play(); }

//Finish playing the sound
void Sound::Finish() {

    //Remove this sound from the sound manager
    SoundManager::remove(this);

    //Delete this sound
    delete this;
}
