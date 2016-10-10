#include "AutoMove.hpp"
#include "AutoMoveManager.hpp"
#include "main.hpp"

#include "math.h"

//Constant speed reduction faster.
//This allows speed precision to be increased
const int AutoMove::SpeedReductionFactor = 10;

//Create the AutoMoveManager
AutoMoveManager * AutoMove::Mgr = new AutoMoveManager();


//A small function that scales down what
//by the gcd of s and SpeedReductionFactor
inline int AutoMove::scaleDown(int what, int s) {
    return (int)round((double)what/(double)gcd(abs(s),SpeedReductionFactor));
}

//Constructor:
//By dividing speed by the gcd of s and
//SpeedReductionFactor, we are allowing the item
//to move more often, thus allowing better graphics
//without loosing accuracy since speed will still be an int
//If each speed was scaled by the same factor, each item could
//move when the timer timesout. However, if we did that, it is
//possible we would have a decimal speed, which would make no sense
//As such we create the variable MoveTurn so that each item can have
//their s scaled down to whatever is best for the user and will not
//loose any precision. MoveTurn will the have certain items skip
//MoveTurn - 1 moves to account for the difference in scaling across all
//move items. How many turns have passed is kept track of by TurnNumber
AutoMove::AutoMove(int s) : speed(scaleDown(s,s)),
    MoveTurn(scaleDown(SpeedReductionFactor,s)) {

    //First turn
    TurnNumber = 1;

    //Add this to the manager
    Mgr->add(this);
}

//Destructor
AutoMove::~AutoMove() {}// Mgr->remove(this); }


//Start moving all AutoMoves
void AutoMove::start() { Mgr->start(); }

//The move function
bool AutoMove::move() {

    //Before move
    if (!beforeTurn()) return false;

    //If the item is ready to move
    //Then move and reset turn number
    if ((TurnNumber++) >= MoveTurn) {
        setPos(x(),y()+speed);
        TurnNumber = 1;

        //After move
        return afterMove();
    }

    //This object should still exit
    return true;
}
