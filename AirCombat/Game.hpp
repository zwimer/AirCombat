#ifndef GAME_H
#define GAME_H


class Game {

public:
    Game(QWidget *parent = NULL);

    QGraphicsScene * theScene;
    Player *P1;
    Score *theScore;
private:

};



#endif // GAME_H
