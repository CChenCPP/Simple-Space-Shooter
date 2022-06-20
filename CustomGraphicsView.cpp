#include "CustomGraphicsView.h"
#include <Game.h>
#include <iostream>

extern Game* game;

CustomGraphicsView::CustomGraphicsView(QWidget* parent) : QGraphicsView(parent)
{
}

CustomGraphicsView::CustomGraphicsView(CustomGraphicsScene* scene, QWidget* parent) : QGraphicsView(scene, parent)
{
    setFixedSize(scene->sceneWidth,scene->sceneHeight);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void CustomGraphicsView::mousePressEvent(QMouseEvent* event)
{
    game->player->setFocus();
}
