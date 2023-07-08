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

    // set gates
    QPixmap line(200, 6);
    QPainter *painter = new QPainter(&line);
    painter->setPen(QPen(Qt::black, Qt::DashLine));
    painter->drawRect(0, 0, 200, 6);
    gates[0] = this->addPixmap(line);
    gates[0]->setPos(348, -3);
    gates[1] = this->addPixmap(line);
    gates[1]->setPos(348, 892);
    delete painter;

    // set refresh timer
    refresh_timer = new QTimer(this);
    connect(refresh_timer, &QTimer::timeout, this, &Soccer_Mode::refresh);
    refresh_timer->start(3);

    // tank
    tank[0] = new Soccer_Tank(tanks[0], walls);
    tank[0]->item->setPos(484, 96);
    this->addItem(tank[0]->item);

    tank[1] = new Soccer_Tank(tanks[1], walls);
    tank[1]->item->setPos(484, 800);
    this->addItem(tank[1]->item);

    tank[0]->set_enemy(tank[1]);
    tank[1]->set_enemy(tank[0]);

    //set ball
    ball = new Ball(walls, tank);
    this->addItem(ball->item);

    // set score board
    score_board = new Score_Board(3);
    score = this->addWidget(score_board);
    score->setPos(0, 0);

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

    if(ball->item->collidesWithItem(gates[0]))
    {
        score_board->gain_score(1);
        this->removeItem(ball->item);
        delete ball;
        refresh_timer->stop();
        Warning("2号玩家进球！").exec();
        ball = new Ball(walls, tank);
        this->addItem(ball->item);
        refresh_timer->start();
    }

    if(ball->item->collidesWithItem(gates[1]))
    {
        score_board->gain_score(0);
        this->removeItem(ball->item);
        delete ball;
        refresh_timer->stop();
        Warning("1号玩家进球！").exec();
        ball = new Ball(walls, tank);
        this->addItem(ball->item);
        refresh_timer->start();
    }

    if(score_board->game_over())
    {
        refresh_timer->stop();
        Warning(QString("%1号玩家胜利！").arg(score_board->game_over())).exec();
        ui->set_scene(menu);
        return;
    }
}

void Soccer_Mode::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    // 1P
    case Qt::Key_P:
        refresh_timer->stop();
        Palse(ui, menu).exec();
        refresh_timer->start();
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

Soccer_Mode::~Soccer_Mode()
{
    delete tank[0], delete tank[1];
    delete ball, delete score_board, delete score;
    delete background, delete refresh_timer;
    for(int i = 0 ; walls[i] != nullptr; ++i)
    {
        delete walls[i];
    }
}
