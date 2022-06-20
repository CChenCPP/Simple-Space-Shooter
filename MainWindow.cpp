#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , UI(new Ui::MainWindow)
{
    UI->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete UI;
}

