#include "Player.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"


Player::Player() {

    //Make this player focusable
    this->setFlag(QGraphicsItem::ItemIsFocusable);

    //Make this the focus item
    this->setFocus();
}

void Player::keyPressEvent(QKeyEvent *e) {

    //Move left
    if (e->key() == Qt::Key_Left) {
        if (pos().x() > 0)
             setPos(x()-10,y());
    }

    //Move right
    else if (e->key() == Qt::Key_Right) {
        if (pos().x() + 100 < 800)    //CHANGE
            setPos(x()+10,y());
    }

    //Shoot
    else if (e->key() == Qt::Key_Space) {

        //Create a new bullet
        Bullet *b = new Bullet();
        b->setPos(x(),y());

        //Add the bullet to the scene
        scene()->addItem(b);
    }

}

//Create a new enemy
void Player::spawn() {

    Enemy *e = new Enemy();
    scene()->addItem(e);
}
