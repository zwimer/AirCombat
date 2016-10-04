#include "SoundPlayer.hpp"
#include "AudioController.hpp"
#include "Game.hpp"

//Constructor
soundPlayer::soundPlayer(const char *Which) {

    //Add this sound to the controller
    theGame->audioController->add(this);

    //Set media
    setMedia(QUrl(Which));

    //Notify when finished
    QObject::connect(this, SIGNAL(mediaStatusChanged()), this, SLOT(finishSound()));

    //Play
    play();
}

//Finish sound
void soundPlayer::finishSound() {

    if (QMEDIAPLAYER_)

    //Remove this from the sound database
    theGame->audioController->soundsPlaying.erase(this);

    //Delete this
    delete this;
}
