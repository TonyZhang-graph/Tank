#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QTimer>
#include <QTransform>
#include <QKeyEvent>

#include <QString>
#include <QGraphicsTextItem>
#include <list>

#include "bullet.h"
#include "tankbase.h"

class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GameScene(QObject *parent = nullptr);
    QGraphicsPixmapItem background[49];
    QPixmap bg_img;
    QGraphicsTextItem *text;
    QGraphicsItem* walls[40] = {NULL};
    std::list<Bullet> bullets;

    QTimer *refresh_timer;

    void refresh();
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

    tankbase *tank;
signals:

};

#endif // GAMESCENE_H
