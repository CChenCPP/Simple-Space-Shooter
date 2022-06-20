#pragma once
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QMediaPlayer>

class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet(int damage = 60, QGraphicsItem* parent = nullptr);

private:
    QTimer timer;
    int damage;
    QMediaPlayer bulletSound;

    void damageEnemies();

private slots:
    void move();
};

