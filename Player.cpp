#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <Bullet.h>
#include "Utility.h"
#include <iostream>

Player::Player(QGraphicsItem* parent) : QGraphicsRectItem(parent)
{
    setRect(0,0,75,100);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}

bool Player::validXmovement(int xDelta)
{
    return x() + xDelta >= 0 && x() + rect().width() + xDelta <= scene()->width();
}

bool Player::validYmovement(int yDelta)
{
    return y() + yDelta >= 0 && y() + rect().height() + yDelta <= scene()->height();
}

bool Player::withinBoundaries(int xDelta, int yDelta)
{
    return validXmovement(xDelta) && validYmovement(yDelta);
}

void Player::keyPressEvent(QKeyEvent* event)
{
    switch(event->key()){
        case Qt::Key_Left:
            if (withinBoundaries(-50, 0)){
                setPos(x() - 50, y());
            }
            break;
        case Qt::Key_Right:
            if (withinBoundaries(50, 0)){
                setPos(x() + 50, y());
            }
            break;
//        case Qt::Key_Down:
//            if (withinBoundaries(0, 10)){
//                setPos(x(), y() + 10);
//            }
//            break;
//        case Qt::Key_Up:
//        if (withinBoundaries(0, -10)){
//            setPos(x(), y() - 10);
//        }
//             break;
        case Qt::Key_Space:
           Bullet* bullet = new Bullet(25);
           bullet->setPos(this->x() + RNG::randomNum(0, this->rect().width() - bullet->rect().width()), this->y());
           scene()->addItem(bullet);
    }
}

// public slot methods
void Player::onAddedToScene()
{
    setPos(scene()->width()/2 - rect().width()/2, scene()->height() - rect().height());
}
