#pragma once
#include <QGraphicsView>
#include <CustomGraphicsScene.h>

class CustomGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    CustomGraphicsView(QWidget* parent = nullptr);
    CustomGraphicsView(CustomGraphicsScene* scene, QWidget* parent = nullptr);

private:
    void mousePressEvent(QMouseEvent* event);
};

