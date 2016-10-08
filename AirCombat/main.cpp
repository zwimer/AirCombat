#include <QApplication>

#include "Game.hpp"

//Must make the game global
Game * theGame;

//Small gcd function
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

//Main function
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    //Run the game
    theGame = new Game();

    //Finish the program
    return a.exec();
}
