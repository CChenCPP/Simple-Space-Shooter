#include "Bullet.h"
#include <QGraphicsScene>
#include "Enemy.h"
#include <iostream>

extern QAudioOutput audioOutput;

Bullet::Bullet()
{
    setRect(0,0,10,50);
    connect(&timer,&QTimer::timeout,this,Bullet::move);
    timer.start(25);
}

Bullet::Bullet(int damage) : damage(damage)
{
    setRect(0,0,10,50);
    bulletSound.setSource(QUrl("qrc:/gun/Sounds/Laser_1.mp3"));
    bulletSound.setAudioOutput(&audioOutput);
    bulletSound.play();
    connect(&timer,&QTimer::timeout,this,Bullet::move);
    timer.start(25);
}

void Bullet::damageEnemies()
{
    QList<QGraphicsItem*> collidingItems = scene()->collidingItems(this);
    for (auto item : collidingItems){
        if (typeid(*item) == typeid(Enemy)){
            auto enemy = static_cast<Enemy*>(item);
            enemy->HP -= damage;
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
}

void Bullet::move()
{
    setPos(x(), y() - 10);
    damageEnemies();
    if (y() < 0 - rect().height()){
        scene()->removeItem(this);
        delete this;
    }
}
