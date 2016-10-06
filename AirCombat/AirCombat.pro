#-------------------------------------------------
#
# Project created by QtCreator 2016-10-02T00:26:30
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AirCombat
TEMPLATE = app


SOURCES += main.cpp \
    Bullet.cpp \
    Game.cpp \
    Enemy.cpp \
    Player.cpp \
    Score.cpp \
    Health.cpp \
    Projectile.cpp \
    Shooter.cpp \
    BasicEnemy.cpp \
    AutoMove.cpp \
    WindowManager.cpp \
    Sound.cpp \
    SoundManager.cpp

HEADERS  += \
    Bullet.hpp \
    Game.hpp \
    Enemy.hpp \
    Player.hpp \
    Score.hpp \
    Health.hpp \
    Projectile.hpp \
    Shooter.hpp \
    BasicEnemy.hpp \
    main.hpp \
    AutoMove.hpp \
    WindowManager.hpp \
    Sound.hpp \
    SoundManager.hpp

FORMS    +=

RESOURCES += \
    ResFile.qrc
