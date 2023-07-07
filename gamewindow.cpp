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

    scene = nullptr;

    music = new QSoundEffect;
    music->setSource(QUrl::fromLocalFile(Music_Property::music_url));
    music->setLoopCount(QSoundEffect::Infinite);
    music->setVolume(0.5f);
    music->play();
}

void GameWindow::set_scene(QGraphicsScene *_scene)
{
//    if(scene != nullptr)
//    {
//        delete scene;
//    }
    scene = _scene;

    ui->view->setScene(scene);

    ui->view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->view->setFixedSize(896, 896);
    ui->view->verticalScrollBar()->blockSignals(true);
    ui->view->horizontalScrollBar()->blockSignals(true);
}

GameWindow::~GameWindow()
{
    delete ui;
    delete scene;
}

void GameWindow::change_music_state()
{
    if(Music_Property::music)
    {
        music->play();
    }
    else
    {
        music->stop();
    }
}
