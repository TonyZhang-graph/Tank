#include "gamescene.h"

GameScene::GameScene(QObject *parent)
    : QGraphicsScene{parent}
{
    bg_img.load(":/resource/Environment/dirt.png");

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

    // set map
//    QPixmap wall_img;
//    wall_img.load("C:/Users/Zhang/Desktop/res/sandbagBeige.png");
//    QGraphicsPixmapItem sandbag;
//    sandbag.setPixmap(wall_img);
//    this->addItem(&sandbag);
//    sandbag.setPos(100, 100);

    // set refresh timer
    refresh_timer = new QTimer(this);
    connect(refresh_timer, &QTimer::timeout, this, &GameScene::refresh);
    refresh_timer->start(3);

    // tank
    tank = new tankbase(walls);
    this->addItem(tank->item);

    // debug text
    text = new QGraphicsTextItem;
    this->addItem(text);
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

    p = nullptr;

    // refresh debug text
    auto topleft = tank->item->mapToScene(tank->item->boundingRect().topLeft()), bottomright = tank->item->mapToScene(tank->item->boundingRect().bottomRight());
    text->setPlainText("heading = " + QString::number(tank->heading) + " pos = " + QString::number(tank->item->x()) + ", " + QString::number(tank->item->y())
                       + "\nBounding Rect: " + QString::number(topleft.x()) + ", " + QString::number(topleft.y()) + "; " + QString::number(bottomright.x()) + ", " + QString::number(bottomright.y())
                       + "\nNumber of Bullets: " + QString::number(bullets.size()));
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
        p = new Palse(this);
        p->exec();
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
