#pragma once
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include <QMediaPlayer>

class Bullet : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Bullet();
    Bullet(int damage);

private:
    QTimer timer;
    int damage;
    QMediaPlayer bulletSound;

    void damageEnemies();

private slots:
    void move();
};

