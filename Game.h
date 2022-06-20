#pragma once
#include <Player.h>
#include <CustomGraphicsScene.h>
#include <CustomGraphicsView.h>
#include <Enemy.h>
#include <Score.h>
#include <Health.h>
#include <QMediaPlayer>

class Game
{

public:
    CustomGraphicsScene* mainScene;
    CustomGraphicsView* mainView;
    Player* player;
    QTimer* levelIncreaseTimer;
    QTimer* enemySpawnTimer;
    int spawnRateMs;
    Score* score;
    Health* health;
    QMediaPlayer* bgMusic;
    QTimer* bgMusicLoopTimer;
    Game();

    void run();

private:
    void setup();
};

