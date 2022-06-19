#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication game(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return game.exec();
}
