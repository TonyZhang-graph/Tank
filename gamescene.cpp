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
    tank = new tankbase(tanks[0], walls);
    this->addItem(tank->item);

    ui = _ui;
    menu = _menu;
}

void GameScene::refresh() {

    // refresh tank
    tank->refresh();

    // refresh bullets
    std::list<Bullet>::iterator it;
    for (it = bullets.begin(); it != bullets.end(); ++it) {
        it->refresh();

        if (it->collide_with_walls()) {
            this->removeItem(it->item);
            bullets.erase(it);
        }
    }
}

void GameScene::keyPressEvent(QKeyEvent *event){

    switch(event->key())
    {
    case Qt::Key_A:
        tank->turning_left = true;
        break;
    case Qt::Key_S:
        tank->moving = -1;
        break;
    case Qt::Key_D:
        tank->turning_right = true;
        break;
    case Qt::Key_W:
        tank->moving = 1;
        break;
    case Qt::Key_P:
        Palse(ui, menu).exec();
        break;

    case Qt::Key_Space:
        auto center = tank->item->mapToScene(tank->item->boundingRect().center());
        bullets.push_back(Bullet(center, tank->heading, walls));
        this->addItem(bullets.back().item);
        break;
    }
}

void GameScene::keyReleaseEvent(QKeyEvent *event){

    switch(event->key())
    {
    case Qt::Key_A:
        tank->turning_left = false;
        break;
    case Qt::Key_S:
        tank->moving = 0;
        break;
    case Qt::Key_D:
        tank->turning_right = false;
        break;
    case Qt::Key_W:
        tank->moving = 0;
        break;
    }
}
