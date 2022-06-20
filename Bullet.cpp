#include "Bullet.h"
#include <QGraphicsScene>
#include "Enemy.h"
#include <iostream>

extern QAudioOutput audioOutput;

Bullet::Bullet(int damage, QGraphicsItem* parent) : QGraphicsPixmapItem(parent), damage(damage)
{
    bulletSound.setSource(QUrl("qrc:/Sounds/Sounds/Laser_1.mp3"));
    bulletSound.setAudioOutput(&audioOutput);
    bulletSound.play();
    setPixmap(QPixmap(":/Images/Images/Laser_Bullet1.png"));
    pixmap().scaled(5,50);
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
    if (y() < 0 - pixmap().height()){
        scene()->removeItem(this);
        delete this;
    }
}
