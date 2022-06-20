#include "Score.h"
#include "Utility.h"
#include <QFont>

Score::Score(QGraphicsItem* parent) : score(0), QGraphicsTextItem(parent)
{
    setPlainText("Score: " + Parse::toQString(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));
}

// public methods
int Score::getScore()
{
    return score;
}

void Score::increaseScore(int amount)
{
    score += amount;
}

// public slot methods
void Score::onEnemiesDestroyed(int count)
{
    increaseScore(count);
    setPlainText("Score: " + Parse::toQString(score));
}
