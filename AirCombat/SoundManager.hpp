#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <set>

//Forward declarations
class Sound;

//A class with only static items used for
//managing all instances of the sound class
class SoundManager {
public:

    //Prevent instantiation
    SoundManager()=delete;

    //Create a new sound
   static void newSound(const char* n);

    //Methods that are public, but act as private with friend
    //class Sound since only this class can create new Sounds:

    //Remove a sound
    static void remove(Sound* s);

private:

    //Representation
    static std::set<Sound*const> *allSounds;
};

#endif // SOUNDMANAGER_H
