#include "MainWindow.h"
#include <QApplication>
#include <Game.h>
#include <QAudioOutput>

QApplication* app;
Game* game;
QAudioOutput audioOutput;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    game = new Game();
    game->run();

    return app.exec();
}
