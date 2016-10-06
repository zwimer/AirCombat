#include "SoundManager.hpp"
#include "Sound.hpp"

//Create a set of sound pointers
std::set<Sound*const>* SoundManager::allSounds = new std::set<Sound*const>();

//Create a new sound
void SoundManager::newSound(const char* n) {

    //Create a new media player
    Sound* p = new Sound(n);

    //Remember this
    allSounds->insert(p);

    //Play the sound
    p->play();
}

//Remove a sound
void SoundManager::remove(Sound* s) { allSounds->erase(s); }
