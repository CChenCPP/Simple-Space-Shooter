#include "CustomGraphicsScene.h"
#include "Enemy.h"
#include "Utility.h"

CustomGraphicsScene::CustomGraphicsScene(QObject* parent) : QGraphicsScene(parent), checkEnemiesHealthTimer(new QTimer())
{
    setSceneRect(0,0,sceneWidth,sceneHeight);
    connect(checkEnemiesHealthTimer,&QTimer::timeout,this,&CustomGraphicsScene::destroyEnemies);
    checkEnemiesHealthTimer->start(50);
}

void CustomGraphicsScene::addPlayer(Player* player)
{
    addItem(player);
    emit playerAdded();
}

void CustomGraphicsScene::destroyEnemies()
{
    int count = 0;
    auto itemList = items();
    for (auto item : itemList){
        if (typeid(*item) == typeid(Enemy)){
            Enemy* enemy = static_cast<Enemy*>(item);
            if (enemy->HP <= 0){
               removeItem(enemy);
               delete enemy;
               ++count;
            }
        }
    }
    emit enemiesDestroyed(count);
}

void CustomGraphicsScene::spawn()
{
    Enemy* enemy = new Enemy();
    this->addItem(enemy);
    enemy->setPos(RNG::randomNum(0,this->width() - enemy->rect().width()), RNG::randomNum(0,this->height() / 2 - enemy->rect().height()));
}
