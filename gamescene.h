#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QTransform>
#include <QKeyEvent>

#include <QString>
#include <QGraphicsTextItem>
#include <list>

#include "bullet.h"
#include "tankbase.h"
#include "palse.h"

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

    Palse *p;
signals:

};

#endif // GAMESCENE_H
