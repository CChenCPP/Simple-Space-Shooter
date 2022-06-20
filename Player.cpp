#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <Bullet.h>
#include "Utility.h"
#include <iostream>

Player::Player(QGraphicsItem* parent) : QGraphicsPixmapItem(parent)
{
    QPixmap icon = QPixmap(":/Images/Images/Player_Helicopter1.png");
    QPixmap scaledIcon = icon.scaled(60,100);
    setPixmap(scaledIcon);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}

bool Player::validXmovement(int xDelta)
{
    return x() + xDelta >= 0 - pixmap().width()/2 && x() + pixmap().width()/2 + xDelta <= scene()->width();
}

bool Player::validYmovement(int yDelta)
{
    return y() + yDelta >= 0 - pixmap().height()/2 && y() + pixmap().height()/2 + yDelta <= scene()->height();
}

bool Player::withinBoundaries(int xDelta, int yDelta)
{
    return validXmovement(xDelta) && validYmovement(yDelta);
}

void Player::keyPressEvent(QKeyEvent* event)
{
    switch(event->key()){
        case Qt::Key_Left:
            if (withinBoundaries(-30, 0)){
                setPos(x() - 30, y());
            }
            break;
        case Qt::Key_Right:
            if (withinBoundaries(30, 0)){
                setPos(x() + 30, y());
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
           Bullet* bullet = new Bullet();
           bullet->setPos(this->x() + RNG::randomNum(0, this->pixmap().width() - bullet->pixmap().width()), this->y());
           scene()->addItem(bullet);
    }
}

// public slot methods
void Player::onAddedToScene()
{
    setPos(scene()->width()/2 - pixmap().width()/2, scene()->height() - pixmap().height());
}
