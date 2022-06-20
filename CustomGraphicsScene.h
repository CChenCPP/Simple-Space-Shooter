#pragma once
#include <QGraphicsScene>
#include <Player.h>
#include <Enemy.h>

class CustomGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    static constexpr int sceneWidth = 800;
    static constexpr int sceneHeight = 600;
    QTimer* checkEnemiesHealthTimer;

    CustomGraphicsScene(QObject* parent = nullptr);
    void addPlayer(Player* player);
    void destroyEnemies();
    void spawn();

signals:
    void enemiesDestroyed(int count);
    void playerAdded();
};

