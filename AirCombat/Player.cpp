#include "Player.hpp"
#include "Bullet.hpp"


Player::Player() {

    //Make this player focusable
    this->setFlag(QGraphicsItem::ItemIsFocusable);

    //Make this the focus item
    this->setFocus();
}

void Player::keyPressEvent(QKeyEvent *e) {

    //Move left
    if (e->key() == Qt::Key_Left) {

        setPos(x()-10,y());
    }

    //Move right
    else if (e->key() == Qt::Key_Right) {

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
