#include "Game.h"

extern QAudioOutput audioOutput;

Game::Game() :
    mainScene(new CustomGraphicsScene())
  , mainView(new CustomGraphicsView(mainScene))
  , player(new Player())
  , enemySpawnTimer(new QTimer())
  , score(new Score())
  , health(new Health())
  , bgMusic(new QMediaPlayer())
  , bgMusicLoopTimer(new QTimer())
{
    setup();
}

// public methods
void Game::run(){
    enemySpawnTimer->start(250);
    mainView->show();
}

// private methods
void Game::setup()
{
    QObject::connect(enemySpawnTimer,&QTimer::timeout,mainScene,CustomGraphicsScene::spawn);
    QObject::connect(mainScene,&CustomGraphicsScene::playerAdded,player,&Player::onAddedToScene);
    QObject::connect(mainScene,&CustomGraphicsScene::enemiesDestroyed,score,&Score::onEnemiesDestroyed);
    mainScene->addPlayer(player);
    mainScene->addItem(score);
    mainScene->addItem(health);
    QObject::connect(bgMusicLoopTimer,&QTimer::timeout,bgMusic,&QMediaPlayer::play);
    bgMusicLoopTimer->start(5000);
    bgMusic->setSource(QUrl("qrc:/background/Sounds/UFO.mp3"));
    bgMusic->setAudioOutput(&audioOutput);
    bgMusic->play();
}
