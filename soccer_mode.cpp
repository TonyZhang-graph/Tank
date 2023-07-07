#include "soccer_mode.h"

Soccer_Mode::Soccer_Mode(GameWindow *_ui, QGraphicsScene *_menu, const QString &img_url, QString *tanks, QObject *parent) : QGraphicsScene{parent}
{
    QPixmap bg_img(img_url);

    background = new QGraphicsPixmapItem[49];
    QGraphicsPixmapItem *p_background = background;

    // draw background image
    for (int i = 0; i < 49; ++i, ++p_background) {
        p_background->setPixmap(bg_img);
        this->addItem(p_background);
        p_background->setPos((i % 7) << 7, (i / 7) << 7);
    }

    // set walls
    walls[0] = new QGraphicsRectItem(0, -10, 896, 10);
    walls[1] = new QGraphicsRectItem(0, 896, 896, 10);
    walls[2] = new QGraphicsRectItem(-10, 0, 10, 896);
    walls[3] = new QGraphicsRectItem(896, 0, 10, 896);

    // set refresh timer
    refresh_timer = new QTimer(this);
    connect(refresh_timer, &QTimer::timeout, this, &Soccer_Mode::refresh);
    refresh_timer->start(3);

    // tank
    tank[0] = new Soccer_Tank(tanks[0], walls);
    tank[0]->item->setPos(400, 100);
    this->addItem(tank[0]->item);

    tank[1] = new Soccer_Tank(tanks[1], walls);
    tank[1]->item->setPos(400, 500);
    this->addItem(tank[1]->item);

    //set ball
    ball = new Ball(walls,tank);
    this->addItem(ball->item);

    // set menu
    ui = _ui;
    menu = _menu;
}

void Soccer_Mode::refresh() {

    // refresh tank
    tank[0]->refresh();
    tank[1]->refresh();

    // refresh soccer
    ball->refresh();
}

void Soccer_Mode::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    // 1P
    case Qt::Key_P:
        Palse(ui, menu).exec();
        break;

    case Qt::Key_A:
        tank[0]->turning_left = true;
        break;
    case Qt::Key_S:
        tank[0]->moving = -1;
        break;
    case Qt::Key_D:
        tank[0]->turning_right = true;
        break;
    case Qt::Key_W:
        tank[0]->moving = 1;
        break;

    // 2P
    case Qt::Key_J:
        tank[1]->turning_left = true;
        break;
    case Qt::Key_K:
        tank[1]->moving = -1;
        break;
    case Qt::Key_L:
        tank[1]->turning_right = true;
        break;
    case Qt::Key_I:
        tank[1]->moving = 1;
        break;
    }
}

void Soccer_Mode::keyReleaseEvent(QKeyEvent *event){

    switch(event->key())
    {
    case Qt::Key_A:
        tank[0]->turning_left = false;
        break;
    case Qt::Key_S:
        tank[0]->moving = 0;
        break;
    case Qt::Key_D:
        tank[0]->turning_right = false;
        break;
    case Qt::Key_W:
        tank[0]->moving = 0;
        break;

    case Qt::Key_J:
        tank[1]->turning_left = false;
        break;
    case Qt::Key_K:
        tank[1]->moving = 0;
        break;
    case Qt::Key_L:
        tank[1]->turning_right = false;
        break;
    case Qt::Key_I:
        tank[1]->moving = 0;
        break;
    }
}
