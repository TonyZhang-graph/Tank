#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    this->setFixedSize(896, 896);
    this->setWindowTitle("Tank Battle");
    this->setWindowIcon(QIcon(":/resource/Tanks/tankGreen.png"));

    scene = new GameScene;

    this->ui->view->setScene(scene);
    this->ui->view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->ui->view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->ui->view->setFixedSize(896, 896);
    this->ui->view->verticalScrollBar()->blockSignals(true);
    this->ui->view->horizontalScrollBar()->blockSignals(true);

}

GameWindow::~GameWindow()
{
    delete ui;
    delete scene;
}
