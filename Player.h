#pragma once
#include <QGraphicsPixmapItem>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(QGraphicsItem* parent = nullptr);

private:

    bool validXmovement(int xDelta);
    bool validYmovement(int yDelta);
    bool withinBoundaries(int xDelta, int yDelta);
    void keyPressEvent(QKeyEvent* event);

public slots:
    void onAddedToScene();
};

