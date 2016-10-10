#include "AutoMoveManager.hpp"
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
void AutoMoveManager::remove(AutoMove *w) { Moving.erase(w); delete w; }

//Move all Moving
void AutoMoveManager::moveAll() {

    //Move each AutoMove, and record which were deleted
    std::vector<AutoMove*> toRemove;
    for(AutoMove* i : Moving)
        if (!i->move())
            toRemove.push_back(i);

    //Delete each deleted AutoMove
    for(AutoMove* i: toRemove) Moving.remove(i);
}
