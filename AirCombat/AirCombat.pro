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

#QMAKE_CXXFLAGS += -O3 -march=native -flto -D TEST

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
    Sound.cpp \
    SoundManager.cpp \
    Missile.cpp \
    FastEnemy.cpp \
    SmartScene.cpp \
    AbstractTurret.cpp \
    GunnerEnemy.cpp \
    AutoMoveManager.cpp \
    BossEnemy.cpp

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
    Sound.hpp \
    SoundManager.hpp \
    Missile.hpp \
    FastEnemy.hpp \
    SmartScene.hpp \
    AbstractTurret.hpp \
    Turret.hpp \
    GunnerEnemy.hpp \
    AutoMoveManager.hpp \
    BossEnemy.hpp

FORMS    +=

RESOURCES += \
    ResFile.qrc
