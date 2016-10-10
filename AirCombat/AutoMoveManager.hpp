#ifndef AUTOMOVEMANAGER_H
#define AUTOMOVEMANAGER_H

#include<Set>

#include<QTimer>
#include<QObject>

//Forward declearations
class AutoMove;

//A class meant for managing automoves (created for efficiency)
class AutoMoveManager : public QObject {
    Q_OBJECT
public:

    //Constructor
    AutoMoveManager();

    //Destructor
    ~AutoMoveManager();

    //Start moving AutoMoves
    void start();

    //Add AutoMove
    void add(AutoMove* w);

    //Remove AutoMove
    void remove(AutoMove* w);

private slots:

    //Move all Moving
    void moveAll();

private:

    //Representation
    QTimer *t;
    std::set<AutoMove*> Moving;
};

#endif // AUTOMOVEMANAGER_H
