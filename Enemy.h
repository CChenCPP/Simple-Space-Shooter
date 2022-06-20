#pragma once
#include <QGraphicsPixmapItem>
#include <QTimer>

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    static constexpr int minWidth = 25;
    static constexpr int minHeight = 25;
    static constexpr int maxWidth = 75;
    static constexpr int maxHeight = 75;
    int HP;

    Enemy();
    void spawn();

private:
    QTimer timer;

private slots:
    void move();
};

