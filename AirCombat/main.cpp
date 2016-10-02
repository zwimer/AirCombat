#include <QApplication>

#include "Game.hpp"

Game * theGame;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Run the game
    theGame = new Game();

    //Finish the program
    return a.exec();
}
