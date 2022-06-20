#include "Enemy.h"
#include <QGraphicsScene>
#include <iostream>
#include "Utility.h"
#include <Game.h>

extern Game* game;

Enemy::Enemy() : HP(RNG::randomNum(50,100))
{
    int width = RNG::randomNum(minWidth,maxWidth);
    int height = RNG::randomNum(minHeight,maxHeight);
    setRect(0,0,width,height);
    connect(&timer,&QTimer::timeout,this,Enemy::move);
    timer.start(25);
}

void Enemy::move()
{
    setPos(x(), y() + 2);

    if (y() > scene()->height()){
        game->health->decreaseHealth(1);
        scene()->removeItem(this);
        delete this;
    }
}
