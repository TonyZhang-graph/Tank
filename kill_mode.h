#ifndef KILL_MODE_H
#define KILL_MODE_H

#pragma once

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QTransform>
#include <QKeyEvent>

#include <QString>
#include <QGraphicsTextItem>
#include <list>

#include "bullet.h"
#include "fight_tank.h"
#include "palse.h"
#include "gamewindow.h"
#include "score_board.h"
#include "warning.h"

class Kill_Mode : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Kill_Mode(GameWindow *_ui, QGraphicsScene *_menu, const QString &img_url, QString *tanks, QObject *parent = nullptr);

    QGraphicsPixmapItem *background;

    QGraphicsItem* walls[40] = {NULL};
    std::list<Bullet> bullets;

    QTimer *refresh_timer;

    GameWindow *ui;
    QGraphicsScene *menu;

    void refresh();
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

    tankbase *tank[2];
signals:

};

#endif // KILL_MODE_H
