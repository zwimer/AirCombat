#include "SmartScene.hpp"
#include "Player.hpp"
#include "Game.hpp"

//Constructor
SmartScene::SmartScene() {}

//Move the player
void SmartScene::mouseMoveEvent(QGraphicsSceneMouseEvent *e)
{ theGame->P1->mouseMoved(e->scenePos()); }

//Fire a bullet
void SmartScene::mousePressEvent(QGraphicsSceneMouseEvent *)
{ theGame->P1->fire(new Bullet(theGame->P1)); }
