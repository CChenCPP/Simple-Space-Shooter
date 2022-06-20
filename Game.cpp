#include "Game.h"
#include <iostream>

extern QAudioOutput audioOutput;

Game::Game() :
    mainScene(new CustomGraphicsScene())
  , mainView(new CustomGraphicsView(mainScene))
  , player(new Player())
  , levelIncreaseTimer(new QTimer())
  , enemySpawnTimer(new QTimer())
  , spawnRateMs(2000)
  , score(new Score())
  , health(new Health())
  , bgMusic(new QMediaPlayer())
  , bgMusicLoopTimer(new QTimer())
{
    setup();
}

// public methods
void Game::run(){
    levelIncreaseTimer->start(15000);
    enemySpawnTimer->start(spawnRateMs);
    mainView->show();
}

// private methods
void Game::setup()
{
    QObject::connect(levelIncreaseTimer,&QTimer::timeout,[&](){
        std::cout << spawnRateMs<< std::endl;
        spawnRateMs = std::max<int>(spawnRateMs - 100, 100);
        enemySpawnTimer->start(spawnRateMs);});
    QObject::connect(enemySpawnTimer,&QTimer::timeout,mainScene,CustomGraphicsScene::spawn);
    QObject::connect(mainScene,&CustomGraphicsScene::playerAdded,player,&Player::onAddedToScene);
    QObject::connect(mainScene,&CustomGraphicsScene::enemiesDestroyed,score,&Score::onEnemiesDestroyed);
    mainScene->addPlayer(player);
    mainScene->addItem(score);
    mainScene->addItem(health);
    bgMusic->setLoops(QMediaPlayer::Infinite);
    QObject::connect(bgMusicLoopTimer,&QTimer::timeout,[&](){ bgMusic->setPosition(0); });
    bgMusicLoopTimer->start(108000);
    bgMusic->setSource(QUrl("qrc:/Sounds/Sounds/UFO.mp3"));
    bgMusic->setAudioOutput(&audioOutput);
    bgMusic->play();
}
