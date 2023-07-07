#include "gamescene.h"

GameScene::GameScene(GameWindow *_ui,QGraphicsScene *_menu, const QString &img_url, QString *tanks, QObject *parent) : QGraphicsScene{parent}
{
    QPixmap bg_img(img_url);

    // draw background image
    for (int i = 0; i < 49; ++i) {
        background[i].setPixmap(bg_img);
        this->addItem(&background[i]);
        background[i].setPos((i % 7) << 7, (i / 7) << 7);
    }

    // set walls
    walls[0] = new QGraphicsRectItem(0, -10, 896, 10);
    walls[1] = new QGraphicsRectItem(0, 896, 896, 10);
    walls[2] = new QGraphicsRectItem(-10, 0, 10, 896);
    walls[3] = new QGraphicsRectItem(896, 0, 10, 896);


    // set refresh timer
    refresh_timer = new QTimer(this);
    connect(refresh_timer, &QTimer::timeout, this, &GameScene::refresh);
    refresh_timer->start(3);

    // tank
    tank[0] = Tank(tanks[0].mid(21, 1), walls);
    tank[0]->item->setPos(400, 100);
    this->addItem(tank[0]->item);

    tank[1] = Tank(tanks[1].mid(21, 1), walls);
    tank[1]->item->setPos(100, 400);
    this->addItem(tank[1]->item);

    ui = _ui;
    menu = _menu;
}

void GameScene::refresh() {

    // refresh tank
    tank[0]->refresh();
    tank[1]->refresh();

    // refresh bullets
    QList<Bullet>::iterator it;
    for (it = bullets.begin(); it != bullets.end();) {
        it->refresh();

        if (it->collide_with_walls())
        {
            this->removeItem(it->item);
            bullets.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void GameScene::keyPressEvent(QKeyEvent *event)
{
    QPointF center;
    switch(event->key())
    {
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

    case Qt::Key_Q:
        center = tank[0]->item->mapToScene(tank[0]->item->boundingRect().center());
        bullets.push_back(Bullet(center, tank[0]->heading, walls));
        this->addItem(bullets.back().item);
        break;

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

    case Qt::Key_U:
        center = tank[1]->item->mapToScene(tank[1]->item->boundingRect().center());
        bullets.push_back(Bullet(center, tank[1]->heading, walls));
        this->addItem(bullets.back().item);
        break;
    }
}

void GameScene::keyReleaseEvent(QKeyEvent *event){

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
