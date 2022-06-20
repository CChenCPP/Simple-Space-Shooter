#include "Health.h"
#include "Utility.h"
#include <QFont>

Health::Health(QGraphicsItem* parent) : health(100), QGraphicsTextItem(parent)
{
    setPlainText("Health: " + Parse::toQString(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
    setPos(0, 25);
}

// public methods
int Health::getHealth()
{
    return health;
}

void Health::decreaseHealth(int amount)
{
    health -= amount;
    setPlainText("Health: " + Parse::toQString(health));
}
