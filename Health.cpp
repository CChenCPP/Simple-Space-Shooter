#include "Health.h"
#include "Utility.h"
#include <QFont>
#include <QMessageBox>
#include <QApplication>
#include <Game.h>

extern QApplication app;
extern Game* game;

Health::Health(QGraphicsItem* parent) : health(100), QGraphicsTextItem(parent)
{
    setPlainText("Health: " + Parse::toQString(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
    setPos(0, 25);
}

// public methods
int Health::getHealth()
{
    return health;
}

void Health::decreaseHealth(int amount)
{
    health -= amount;
    setPlainText("Health: " + Parse::toQString(health));
    if (health == 0){
        QMessageBox gameOver;
        gameOver.setWindowTitle("Game over!");
        gameOver.setText("Your score is " + QString::number(game->score->getScore()));
        gameOver.exec();
        app.closeAllWindows();
    }
}
