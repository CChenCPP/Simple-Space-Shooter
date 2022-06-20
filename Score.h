#pragma once
#include <QGraphicsTextItem>

class Score : public QGraphicsTextItem
{
public:
    Score(QGraphicsItem* parent = nullptr);
    int getScore();
    void increaseScore(int amount = 1);

private:
    int score;

public slots:
    void onEnemiesDestroyed(int count);
};

