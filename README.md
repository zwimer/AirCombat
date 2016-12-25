# AirCombat

AirCombat is a simple game with simple rules:

1. Don't get hit by anything
2. Don't let enemies pass you
3. Have fun!

##Disclaimer

This game is my first experience using QT, and a way for me to practice doing so. I simply made this game to familiarize myself with some basic QT. It has yet to have any optimzations applied and yet to be fully finished. For information regarding preformance boosting optimizations click here TODO.

###Devolpers

Please read the wiki issues page before diving in TODO

##Requirements

This application requires the use of the graphics library QT. It requires qmake 5.7 and C++ 11 to build.

##Installation Instructions:

First, cd into the directory you would like to install this application in

Then git clone this repository
```bash
git clone https://github.com/zwimer/AirCombat
```

Create your build directory as follows
```bash
mkdir AirCombat/build && cd AirCombat/build/
```

After that run qmake and make with the command below
```bash
qmake ../AirCombat/AirCombat.pro && make
```

##Usage

This application takes no arguments. Just open it like you would any application.
