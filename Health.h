#pragma once
#include <QGraphicsTextItem>

class Health : public QGraphicsTextItem
{
public:
    Health(QGraphicsItem* parent = nullptr);
    int getHealth();
    void decreaseHealth(int amount = 1);

private:
    int health;
};

