#include "AutoMoveManager.hpp"
#include "SoundManager.hpp"
#include "AutoMove.hpp"

#include <vector>

//Constructor
AutoMoveManager::AutoMoveManager() {}

//Start moing AutoMoves
void AutoMoveManager::start() {

    //Create a new timer
    t = new QTimer();

    //Connect the moveAll function to a timer
    connect(t, SIGNAL(timeout()), this, SLOT(moveAll()));

    //Have the timer call moveAll every 30 ms
    t->start(30);
}

//Destructor
AutoMoveManager::~AutoMoveManager() { delete t; }

//Add new AutoMove to the manager
void AutoMoveManager::add(AutoMove *w) { Moving.insert(w); }

//Add old AutoMove fromthe manager
void AutoMoveManager::remove(AutoMove *w) { toDelete.push_back(w); }

//Play a sound
void AutoMoveManager::playSound(const char *f) { toPlay.insert(f); }

//Move all Moving
void AutoMoveManager::moveAll() {

    //Move each AutoMove
    for(AutoMove* i : Moving) i->move();

    //Delete each deleted AutoMove
    for(AutoMove* i: toDelete)
    { Moving.erase(i); delete i; }

    //Play all new sounds
    for(const char * i : toPlay)
        SoundManager::newSound(i);

    //Clear todo lists
    toDelete.clear(); toPlay.clear();
}
