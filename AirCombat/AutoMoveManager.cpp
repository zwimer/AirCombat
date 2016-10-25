#include "AutoMoveManager.hpp"
#include "SoundManager.hpp"
#include "AutoMove.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Game.hpp"

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

//Add old AutoMove from the manager
void AutoMoveManager::remove(AutoMove *w) { toDelete.insert(w); }

//Play a sound
void AutoMoveManager::playSound(const char *f) { toPlay.insert(f); }

//Move all Moving
void AutoMoveManager::moveAll() {

    //Move each AutoMove
    for(AutoMove* i : Moving) i->move();

    //Play all new sounds
    for(const char * i : toPlay)
        SoundManager::newSound(i);

    //Get items hitting the player
    QList<QGraphicsItem*> items = theGame->P1->collidingItems();

    //Temporary variables
    Projectile *p;
    Enemy *e;

    //For each of them
    for(auto i : items)

        //If an enemy hits the player
        if ((e = dynamic_cast<Enemy*>(i)) != NULL)
            theGame->GameOver();

        //If an enemy projectile hits the player
        else if ((p = dynamic_cast<Projectile*>(i)) != NULL)
            if (!p->hurtsEnemy()) {

                //Decrease the player's health and delete the projectile
                theGame->P1->health->decrease(p->getDamage());
                toDelete.insert(p);
            }

    //Delete each deleted AutoMove
    for(AutoMove* i: toDelete)
    { Moving.erase(i); delete i; }

    //Clear todo lists
    toDelete.clear(); toPlay.clear();
}
