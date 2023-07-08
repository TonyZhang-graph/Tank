#include "conquer_mode.h"

Conquer_Mode::Conquer_Mode(GameWindow *_ui, QGraphicsScene *_menu, QString *tanks, QObject *parent) : QGraphicsScene{parent}
{
    // tank
    tank[0] = Tank(tanks[0].mid(21, 1), walls);
    tank[0]->item->setPos(400, 100);

    tank[1] = Tank(tanks[1].mid(21, 1), walls);
    tank[1]->item->setPos(400, 596);

    for(int i = 0; i < 49; ++i)
    {
        tiles[i] = new Tile(tank);
        this->addItem(tiles[i]->item);
        tiles[i]->item->setPos((i % 7) << 7, (i / 7) << 7);
    }

    this->addItem(tank[0]->item);
    this->addItem(tank[1]->item);

    tank[0]->set_enemy(tank[1]);
    tank[1]->set_enemy(tank[0]);

    // set walls
    walls[0] = new QGraphicsRectItem(0, -10, 896, 10);
    walls[1] = new QGraphicsRectItem(0, 896, 896, 10);
    walls[2] = new QGraphicsRectItem(-10, 0, 10, 896);
    walls[3] = new QGraphicsRectItem(896, 0, 10, 896);

    record = new QGraphicsPixmapItem[20];

    // load map
    Map map;
    QFile file(":/resource/Maps/map1.map");
    file.open(QIODevice::ReadOnly);
    QDataStream mapfile(&file);
    mapfile.readRawData((char*) &map, sizeof(map));
    file.close();
    map.load(this, walls + 4, record);

    // set refresh timer
    refresh_timer = new QTimer(this);
    connect(refresh_timer, &QTimer::timeout, this, &Conquer_Mode::refresh);
    refresh_timer->start(3);

    score_board = new Score_Board(25);
    score = this->addWidget(score_board);
    score->setPos(0, 0);

    ui = _ui;
    menu = _menu;
}

void Conquer_Mode::refresh() {

    // refresh tank
    tank[0]->refresh();
    tank[1]->refresh();

    // refresh bullets
    for(auto it = bullets.begin(); it != bullets.end();)
    {
        it->refresh();

        if(it->item->collidesWithItem(it->enemy->item))
        {
            it->enemy->hurted(it->attack_value);
            this->removeItem(it->item);
            it = bullets.erase(it);
            continue;
        }

        if(it->time == 3)
        {
            this->removeItem(it->item);
            it = bullets.erase(it);
        }
        else
        {
            ++it;
        }
    }

    if(tank[0]->is_dead())
    {
        tank[0]->reborn();
        tank[0]->item->setPos(400, 100);
    }
    if(tank[1]->is_dead())
    {
        tank[1]->reborn();
        tank[1]->item->setPos(400, 596);
    }

    for(int i = 0; i < 49; ++i)
    {
        bool conquered = tiles[i]->conquer;
        tiles[i]->change_color();
        if(conquered)
        {
            score_board->zero_sum_gain_score(tiles[i]->conquer - 1);
        }
        else
        {
            score_board->gain_score(tiles[i]->conquer - 1);
        }
    }

    if(score_board->game_over())
    {
        refresh_timer->stop();
        Warning(QString("恭喜%1号玩家获胜！").arg(score_board->game_over())).exec();
        ui->set_scene(menu);
        return;
    }
}

void Conquer_Mode::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
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

    case Qt::Key_Q:
        bullets.push_back(Bullet(tank[0]->bullet_url, tank[0]->item->mapToScene(tank[0]->item->boundingRect().center()), tank[0]->heading, walls, tank[1]));
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
        bullets.push_back(Bullet(tank[1]->bullet_url, tank[1]->item->mapToScene(tank[1]->item->boundingRect().center()), tank[1]->heading, walls, tank[0]));
        this->addItem(bullets.back().item);
        break;
    }
}

void Conquer_Mode::keyReleaseEvent(QKeyEvent *event){

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

Conquer_Mode::~Conquer_Mode()
{
    delete refresh_timer;
    delete score_board, delete score;
    delete tank[0], delete tank[1];
    for(int i = 0; walls[i] != nullptr; ++i)
    {
        delete walls[i];
    }
}
