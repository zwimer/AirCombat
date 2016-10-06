#include <QApplication>

#include "Game.hpp"


#include <Sound.hpp>

//Must make the game global
Game * theGame;

//Main function
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);







    //Run the game
    theGame = new Game();

    //Finish the program
    return a.exec();
}
